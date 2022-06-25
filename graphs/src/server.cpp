#include <iostream>
#include <ctime>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

std::string make_daytime_string() {
    std::time_t now = std::time(0);
    return std::ctime((const time_t *)&now);
}

int start_tcp_server(void) {
    /* Create server acceptor */
    try {
        boost::asio::io_service io_service;

        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

        for (;;) {
            //create a socket
            tcp::socket socket(io_service);

            //prepare list 
            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            /* Keep listening */
            /* Accept and send the message time */

        }

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}



