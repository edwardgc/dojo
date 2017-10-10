#include "ChatServer.hpp"
#include "ChatSession.hpp"
#include <functional>

using namespace std;
using boost::asio::ip::tcp;

chat_server::chat_server(boost::asio::io_service& io_service, const tcp::endpoint& endpoint, IChatObserver& p_observer) :
        m_ioService(io_service), m_acceptor(io_service, endpoint), m_observer(p_observer)
{
    cout << __FUNCTION__ << endl;
    shared_ptr<ChatSession> new_session(new ChatSession(m_ioService, m_observer));
    m_acceptor.async_accept(new_session->socket(),
            bind(&chat_server::handle_accept, this, new_session, placeholders::_1));
}

void chat_server::handle_accept(shared_ptr<ChatSession> session, const boost::system::error_code& error)
{
    cout << __FUNCTION__ << endl;
    if (!error)
    {
        session->start();
        shared_ptr<ChatSession> new_session(new ChatSession(m_ioService, m_observer));
        m_acceptor.async_accept(new_session->socket(),
                bind(&chat_server::handle_accept, this, new_session, placeholders::_1));
    }
}

