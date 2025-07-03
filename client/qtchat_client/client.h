#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

class client
{
public:
    client(boost::asio::io_service &service);
    socket_ptr m_sock;
    void connect_handler(const boost::system::error_code & ec);
    void on_write(char * ptr, const boost::system::error_code & err);
    void mywrite();
};

#endif // CLIENT_H
