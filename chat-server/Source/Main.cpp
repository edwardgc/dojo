#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <memory>
#include <functional>
#include <boost/asio.hpp>
#include <ChatMessage.hpp>

using boost::asio::ip::tcp;
using namespace std;

typedef std::deque<ChatMessage> chat_message_queue;

class chat_participant
{
public:
    virtual ~chat_participant()
    {
    }
    virtual void deliver(const ChatMessage& msg) = 0; // ·¢ÑÔ
};

typedef shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
    void join(chat_participant_ptr participant) // 6
    {
        cout << __FUNCTION__ << endl;
        participants_.insert(participant);

        for_each(recent_msgs_.begin(), recent_msgs_.end(),
                bind(&chat_participant::deliver, participant, placeholders::_1)); // 12 ¶¯Ì¬°ó¶¨
    }

    void leave(chat_participant_ptr participant)
    {
        cout << __FUNCTION__ << endl;
        participants_.erase(participant);
    }

    void deliver(const ChatMessage& msg)
    {
        cout << __FUNCTION__ << endl;
        recent_msgs_.push_back(msg);
        while (recent_msgs_.size() > max_recent_msgs)
            recent_msgs_.pop_front();

        for_each(participants_.begin(), participants_.end(),
                bind(&chat_participant::deliver, placeholders::_1, ref(msg))); // 12
    }

private:
    std::set<chat_participant_ptr> participants_;
    enum
    {
        max_recent_msgs = 100
    };
    chat_message_queue recent_msgs_;
};

class chat_session: public chat_participant, public enable_shared_from_this<chat_session>
{
public:
    chat_session(boost::asio::io_service& io_service, chat_room& room)
    :
            socket_(io_service), room_(room)
    {
        cout << __FUNCTION__ << endl;
    }

    tcp::socket& socket()
    {
        cout << __FUNCTION__ << endl;
        return socket_;
    }

    void start()
    {
        cout << __FUNCTION__ << endl;
        room_.join(shared_from_this());

        boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
                bind(&chat_session::handle_read_header, shared_from_this(), placeholders::_1));
    }

    void handle_read_header(const boost::system::error_code& error)
    {
        cout << __FUNCTION__ << endl;
        if (!error && read_msg_.decode_header())
        {
            boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
            bind(&chat_session::handle_read_body, shared_from_this(),
                    placeholders::_1));
        } else
        {
            room_.leave(shared_from_this());
        }
    }

    void handle_read_body(const boost::system::error_code& error)
    {
        cout << __FUNCTION__ << endl;
        if (!error)
        {
            room_.deliver(read_msg_);
            boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
            bind(&chat_session::handle_read_header, shared_from_this(),
                    placeholders::_1));
        } else
        {
            room_.leave(shared_from_this());
        }
    }

    void deliver(const ChatMessage& msg)
    {
        cout << __FUNCTION__ << endl;
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            boost::asio::async_write(socket_,
                    boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                    bind(&chat_session::handle_write, shared_from_this(),
                            placeholders::_1));
        }
    }

    void handle_write(const boost::system::error_code& error)
    {
        cout << __FUNCTION__ << endl;
        if (!error)
        {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
                boost::asio::async_write(socket_, boost::asio::buffer(write_msgs_.front().data(),
                        write_msgs_.front().length()), bind(&chat_session::handle_write, shared_from_this(),
                        placeholders::_1));
            }
        } else
        {
            room_.leave(shared_from_this());
        }
    }

private:
    tcp::socket socket_;
    chat_room& room_;
    ChatMessage read_msg_;
    chat_message_queue write_msgs_;
};

using chat_session_ptr = shared_ptr<chat_session> ;

class chat_server
{
public:
    chat_server(boost::asio::io_service& io_service,
            const tcp::endpoint& endpoint) :
            io_service_(io_service), acceptor_(io_service, endpoint)
    {
        cout << __FUNCTION__ << endl;
        chat_session_ptr new_session(new chat_session(io_service_, room_));
        acceptor_.async_accept(new_session->socket(),
                bind(&chat_server::handle_accept, this, new_session,
                        placeholders::_1));
    }

    void handle_accept(chat_session_ptr session,
            const boost::system::error_code& error)
    {
        cout << __FUNCTION__ << endl;
        if (!error)
        {
            session->start(); // 5
            chat_session_ptr new_session(new chat_session(io_service_, room_));
            acceptor_.async_accept(new_session->socket(),
                    bind(&chat_server::handle_accept, this, new_session,
                            placeholders::_1));
        }
    }

private:
    boost::asio::io_service& io_service_;
    tcp::acceptor acceptor_;
    chat_room room_;
};

typedef shared_ptr<chat_server> chat_server_ptr;

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;

        tcp::endpoint endpoint(tcp::v4(), 1000);
        chat_server_ptr server(new chat_server(io_service, endpoint)); // 1

        io_service.run();
    } catch (std::exception& e)
    {
        std::cerr << "Main Exception: " << e.what() << "\n";
    }

    return 0;
}
