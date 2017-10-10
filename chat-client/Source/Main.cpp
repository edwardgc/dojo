/*
 * Main.cpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;
        tcp::endpoint end_point(boost::asio::ip::address::from_string("127.0.0.1"), 3200);

        tcp::socket socket(io_service);
        socket.connect(end_point);

        for (;;)
        {
            array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.

            cout.write(buf.data(), len);
        }
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}



