#include "ChatSession.hpp"
#include <functional>

using namespace std;
using boost::asio::ip::tcp;

static int userId = 0;

ChatSession::ChatSession(boost::asio::io_service& io_service, IChatObserver& p_observer) :
        socket_(io_service), m_name("user" + to_string(++userId)), m_observer(p_observer)
{
}

tcp::socket& ChatSession::socket()
{
    cout << __FUNCTION__ << endl;
    return socket_;
}

void ChatSession::start()
{
    cout << __FUNCTION__ << " " << m_name << endl;
    m_observer.onNewSession(shared_from_this());

    boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
            bind(&ChatSession::handle_read_header, shared_from_this(), placeholders::_1));
}

void ChatSession::handle_read_header(const boost::system::error_code& error)
{
    cout << __FUNCTION__ << endl;
    if (!error && read_msg_.decode_header())
    {
        boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                bind(&ChatSession::handle_read_body, shared_from_this(), placeholders::_1));
    } else
    {
        m_observer.onSessionClose(shared_from_this());
    }
}

void ChatSession::handle_read_body(const boost::system::error_code& error)
{
    cout << __FUNCTION__ << endl;
    if (!error)
    {
        m_observer.onReceive(shared_from_this(), read_msg_.toString());
        boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
                bind(&ChatSession::handle_read_header, shared_from_this(), placeholders::_1));
    } else
    {
        m_observer.onSessionClose(shared_from_this());
    }
}

void ChatSession::deliver(const string& msg)
{
    cout << __FUNCTION__ << endl;
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_, boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                bind(&ChatSession::handle_write, shared_from_this(), placeholders::_1));
    }
}

void ChatSession::handle_write(const boost::system::error_code& error)
{
    cout << __FUNCTION__ << endl;
    if (!error)
    {
        write_msgs_.pop_front();
        if (!write_msgs_.empty())
        {
            boost::asio::async_write(socket_,
                    boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                    bind(&ChatSession::handle_write, shared_from_this(), placeholders::_1));
        }
    } else
    {
        m_observer.onSessionClose(shared_from_this());
    }
}

std::string ChatSession::getName() const
{
    return m_name;
}

void ChatSession::setName(const std::string& p_name)
{
    m_name = p_name;
}

