#include <boost/asio.hpp>
#include <iostream>
#include "dispatcher.h"
using boost::asio::ip::tcp;

int main(){
    Dispatcher io_dispatcher;

    io_dispatcher.sheldue([]{
        boost::asio::io_service io_service;
        tcp::socket socket(io_service);
        tcp::endpoint ep(boost::asio::ip::address::from_string("10.100.5.175"), 8123);
        char buff[800];
        std::string buff2 = "Hello";
        socket.connect(ep);
        for (;;){
            socket.write_some(boost::asio::buffer(buff2));
            socket.read_some(boost::asio::buffer(buff));
            std::cout << buff << std::endl;
        }
    });
}

