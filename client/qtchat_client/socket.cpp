#include "socket.h"

Socket::Socket() : m_sock(m_service)
{
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 2001);
    //auto funPointer = connect_handler;
    //m_sock.async_connect(ep, connect_handler);
    //m_service.run();
}

void Socket::connect_handler(const boost::system::error_code &ec)
{
    return;
}

