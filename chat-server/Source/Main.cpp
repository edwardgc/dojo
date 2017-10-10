#include <memory>
#include <boost/asio.hpp>
#include "ChatServer.hpp"
#include "DefaultChatObserver.hpp"

using boost::asio::ip::tcp;
using namespace std;

typedef shared_ptr<chat_server> chat_server_ptr;

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;

        tcp::endpoint endpoint(tcp::v4(), 1000);
        DefaultChatObserver observer;
        chat_server_ptr server(new chat_server(io_service, endpoint, observer)); // 1

        io_service.run();
    } catch (std::exception& e)
    {
        std::cerr << "Main Exception: " << e.what() << "\n";
    }

    return 0;
}
