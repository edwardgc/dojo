#pragma once

#include <memory>
#include <deque>
#include <boost/asio.hpp>
#include "ChatMessage.hpp"
#include "ISession.hpp"
#include "IChatObserver.hpp"

using chat_message_queue = std::deque<ChatMessage> ;

class ChatSession: public ISession, public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(boost::asio::io_service& io_service, IChatObserver& p_observer);
    boost::asio::ip::tcp::socket& socket();
    void start();
    void deliver(const std::string& msg) override;
    virtual std::string getName() const override;
    virtual void setName(const std::string&) override;
private:
    void handle_read_header(const boost::system::error_code& error);
    void handle_read_body(const boost::system::error_code& error);
    void handle_write(const boost::system::error_code& error);
    boost::asio::ip::tcp::socket socket_;
    ChatMessage read_msg_;
    chat_message_queue write_msgs_;
    std::string m_name;
    IChatObserver& m_observer;
};

