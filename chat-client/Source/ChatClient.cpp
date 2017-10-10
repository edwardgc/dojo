#define BOOST_THREAD_VERSION 3

#include "ChatClient.hpp"

using boost::asio::ip::tcp;
using namespace std;

ChatClient::ChatClient(boost::asio::io_service& io_service, tcp::resolver::iterator endpoint_iterator) :
        io_service_(io_service), socket_(io_service)
{
    cout << __FUNCTION__ << endl;
    tcp::endpoint endpoint = *endpoint_iterator;
    socket_.async_connect(endpoint, bind(&ChatClient::handle_connect, this, placeholders::_1, ++endpoint_iterator));
}

void ChatClient::write(const ChatMessage& msg)
{
    io_service_.post(bind(&ChatClient::do_write, this, msg));
}

void ChatClient::close()
{
    io_service_.post(bind(&ChatClient::do_close, this));
}

void ChatClient::handle_connect(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator)
{
    if (!error)
    {
        boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
                bind(&ChatClient::handle_read_header, this, placeholders::_1));
    } else if (endpoint_iterator != tcp::resolver::iterator())
    {
        socket_.close();
        tcp::endpoint endpoint = *endpoint_iterator;
        socket_.async_connect(endpoint, bind(&ChatClient::handle_connect, this, placeholders::_1, ++endpoint_iterator));
    }
}

void ChatClient::handle_read_header(const boost::system::error_code& error)
{
    if (!error && read_msg_.decode_header())
    {
        boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                bind(&ChatClient::handle_read_body, this, placeholders::_1));
    } else
    {
        do_close();
    }
}

void ChatClient::handle_read_body(const boost::system::error_code& error)
{
    if (!error)
    {
        std::cout.write(read_msg_.body(), read_msg_.body_length());
        std::cout << "\n";
        boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
                bind(&ChatClient::handle_read_header, this, placeholders::_1));
    } else
    {
        do_close();
    }
}

void ChatClient::do_write(ChatMessage msg)
{
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_, boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                bind(&ChatClient::handle_write, this, placeholders::_1));
    }
}

void ChatClient::handle_write(const boost::system::error_code& error)
{
    if (!error)
    {
        write_msgs_.pop_front();
        if (!write_msgs_.empty())
        {
            boost::asio::async_write(socket_,
                    boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                    bind(&ChatClient::handle_write, this, placeholders::_1));
        }
    } else
    {
        do_close();
    }
}

void ChatClient::do_close()
{
    cout << __FUNCTION__ << endl;
    socket_.close();
}

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query("127.0.0.1", "1000");
        tcp::resolver::iterator iterator = resolver.resolve(query);

        ChatClient c(io_service, iterator);

        thread t(bind((size_t (boost::asio::io_service::*)())&boost::asio::io_service::run, &io_service));

        char line[ChatMessage::max_body_length + 1];
        while (std::cin.getline(line, ChatMessage::max_body_length + 1))
        {
            ChatMessage msg;
            msg.body_length(strlen(line));
            memcpy(msg.body(), line, msg.body_length());
            msg.encode_header();
            c.write(msg);
        }

        c.close();
        t.join();
    } catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

