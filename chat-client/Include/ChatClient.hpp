/*
 * Main.hpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */
#pragma once

#include <deque>
#include <iostream>
#include <boost/asio.hpp>
#include <ChatMessage.hpp>
#include <thread>
#include <functional>
#include <memory>

class IReceiver;

using chat_message_queue = std::deque<ChatMessage>;

class ChatClient
{
public:
    ChatClient(boost::asio::io_service& p_ioService, boost::asio::ip::tcp::resolver::iterator p_endpointIterator);
    void write(const ChatMessage& msg);
    void close();
    void setReceiver(IReceiver* p_receiver);
private:
    void handle_connect(const boost::system::error_code& error,
            boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
    void handle_read_header(const boost::system::error_code& error);
    void handle_read_body(const boost::system::error_code& error);
    void do_write(ChatMessage msg);
    void handle_write(const boost::system::error_code& error);
    void do_close();

    boost::asio::io_service& m_ioService;
    boost::asio::ip::tcp::socket m_socket;
    ChatMessage m_readMsg;
    chat_message_queue m_writeMsgs;
    IReceiver* m_receiver = nullptr;
};

