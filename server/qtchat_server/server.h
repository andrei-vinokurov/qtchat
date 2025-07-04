#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

class server
{
public:
    server(boost::asio::io_service &service);
    socket_ptr m_sock;
    void handle_accept(socket_ptr sock, const boost::system::error_code & err);
    void on_read(char * ptr, const boost::system::error_code & err, std::size_t read_bytes);
    void myread();
    std::string m_str = "false";
    std::string m_str2 = "who?";
};

#endif // SERVER_H
