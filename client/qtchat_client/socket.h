#ifndef SOCKET_H
#define SOCKET_H

#include <boost/bind.hpp>
#include <boost/asio.hpp>
//using boost::asio;

class Socket
{
private:
    boost::asio::ip::tcp::socket m_sock;
    boost::asio::io_service m_service;

public:
    Socket();
    void connect_handler(const boost::system::error_code & ec);
};

#endif // SOCKET_H
