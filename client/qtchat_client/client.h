#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

class client
{
public:
    client(boost::asio::io_service &service);
    boost::asio::ip::tcp::socket m_sock;
    void connect_handler(const boost::system::error_code & ec);
    void on_write(char * ptr, const boost::system::error_code & err);
    void mywrite();
};

#endif // CLIENT_H
