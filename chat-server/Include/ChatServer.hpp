#pragma once

#include <boost/asio.hpp>
#include <memory>
#include "IChatObserver.hpp"

class ChatSession;

class chat_server
{
public:
    chat_server(boost::asio::io_service& io_service, const boost::asio::ip::tcp::endpoint& endpoint, IChatObserver& p_observer);

    void handle_accept(std::shared_ptr<ChatSession> session, const boost::system::error_code& error);

private:
    boost::asio::io_service& m_ioService;
    boost::asio::ip::tcp::acceptor m_acceptor;
    IChatObserver& m_observer;
};

