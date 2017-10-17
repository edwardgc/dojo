#define BOOST_THREAD_VERSION 3

#include "ChatClient.hpp"
#include "IReceiver.hpp"

using boost::asio::ip::tcp;
using namespace std;

ChatClient::ChatClient(boost::asio::io_service& p_ioService, tcp::resolver::iterator p_endpointIterator) :
        m_ioService(p_ioService), m_socket(p_ioService)
{
    cout << __FUNCTION__ << endl;
    tcp::endpoint endpoint = *p_endpointIterator;
    m_socket.async_connect(endpoint, bind(&ChatClient::handle_connect, this, placeholders::_1, ++p_endpointIterator));
}

void ChatClient::write(const ChatMessage& msg)
{
    m_ioService.post(bind(&ChatClient::do_write, this, msg));
}

void ChatClient::setReceiver(IReceiver* p_receiver)
{
    m_receiver = p_receiver;
}

void ChatClient::close()
{
    m_ioService.post(bind(&ChatClient::do_close, this));
}

void ChatClient::handle_connect(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator)
{
    if (!error)
    {
        boost::asio::async_read(m_socket, boost::asio::buffer(m_readMsg.data(), ChatMessage::header_length),
                bind(&ChatClient::handle_read_header, this, placeholders::_1));
    } else if (endpoint_iterator != tcp::resolver::iterator())
    {
        cout << __FUNCTION__ << " Error!"<< endl;
        m_socket.close();
        tcp::endpoint endpoint = *endpoint_iterator;
        m_socket.async_connect(endpoint, bind(&ChatClient::handle_connect, this, placeholders::_1, ++endpoint_iterator));
    }
}

void ChatClient::handle_read_header(const boost::system::error_code& error)
{
    if (!error && m_readMsg.decode_header())
    {
        boost::asio::async_read(m_socket, boost::asio::buffer(m_readMsg.body(), m_readMsg.body_length()),
                bind(&ChatClient::handle_read_body, this, placeholders::_1));
        cout << "success" << endl;
    } else
    {
        cout << __FUNCTION__ << " Error!"<< endl;
        do_close();
    }
}

void ChatClient::handle_read_body(const boost::system::error_code& error)
{
    if (!error)
    {
        std::cout.write(m_readMsg.body(), m_readMsg.body_length());
        std::cout << "\n";
        if(m_receiver!=nullptr)
        {
            m_receiver->onReceive(m_readMsg.toString());
        }
        boost::asio::async_read(m_socket, boost::asio::buffer(m_readMsg.data(), ChatMessage::header_length),
                bind(&ChatClient::handle_read_header, this, placeholders::_1));
    } else
    {
        cout << __FUNCTION__ << " Error!"<< endl;
        do_close();
    }
}

void ChatClient::do_write(ChatMessage msg)
{
    bool write_in_progress = !m_writeMsgs.empty();
    m_writeMsgs.push_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(m_socket, boost::asio::buffer(m_writeMsgs.front().data(), m_writeMsgs.front().length()),
                bind(&ChatClient::handle_write, this, placeholders::_1));
    }
}

void ChatClient::handle_write(const boost::system::error_code& error)
{
    if (!error)
    {
        m_writeMsgs.pop_front();
        if (!m_writeMsgs.empty())
        {
            boost::asio::async_write(m_socket,
                    boost::asio::buffer(m_writeMsgs.front().data(), m_writeMsgs.front().length()),
                    bind(&ChatClient::handle_write, this, placeholders::_1));
        }
    } else
    {
        cout << __FUNCTION__ << " Error!"<< endl;
        do_close();
    }
}

void ChatClient::do_close()
{
    cout << __FUNCTION__ << endl;
    m_socket.close();
}

int mainShell(int argc, char* argv[])
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

