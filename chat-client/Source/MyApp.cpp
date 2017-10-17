/*
 * MyApp.cpp
 *
 *  Created on: 2017Äê9ÔÂ12ÈÕ
 *      Author: cguo005
 */

#include <memory>
#include <wx/wx.h>
#include "MyApp.hpp"
#include "Main.hpp"
#include "ChatClient.hpp"

using boost::asio::ip::tcp;
using namespace std;

MyApp::MyApp(shared_ptr<ChatClient> p_client)
        : m_client(p_client)
{
}

bool MyApp::OnInit()
{
    MainFrame* main = new MainFrame(wxT("Nokia Chat"), m_client);

    main->Show(true);

    return true;
}

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query("127.0.0.1", "1000");
        tcp::resolver::iterator iterator = resolver.resolve(query);

        shared_ptr<ChatClient> client = make_shared<ChatClient>(io_service, iterator);

        MyApp* app = new MyApp(client);
        wxApp::SetInstance(app);

        new thread(bind((size_t (boost::asio::io_service::*)())&boost::asio::io_service::run, &io_service));

        return wxEntry(argc, argv);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

}

