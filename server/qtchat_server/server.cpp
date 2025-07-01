#include "server.h"

server::server(boost::asio::io_service &service) : m_sock(new boost::asio::ip::tcp::socket(service))
{
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::tcp::v4(), 2001); // listen on 2001
    boost::asio::ip::tcp::acceptor acc(service, ep);
    //std::cout << "constructor " << m_sock << std::endl;
    acc.async_accept(*m_sock, boost::bind(&server::handle_accept, this, m_sock, boost::placeholders::_1));
    service.run();
}

void server::handle_accept(socket_ptr sock, const boost::system::error_code & err)
{
    if (err) return;
    m_str = "true";
    // at this point, you can read/write to the socket
    //std::cout << "Client connected" << std::endl;
    //system("PAUSE");
}

void server::on_read(char * ptr, const boost::system::error_code & err, std::size_t read_bytes)
{
    delete[] ptr;
}

void server::myread()
{
    std::cout << "myread " << m_sock << std::endl;
    char * buff = new char[512];
    m_sock->async_receive(boost::asio::buffer(buff, 512), boost::bind(&server::on_read, this, buff, boost::placeholders::_1, boost::placeholders::_2));

    for(int i = 0; i < 512; i++)
    {
        if(*(buff + i) != '\0') std::cout << *(buff + i);
        else break;
    }
}


/*

    boost::asio::io_service service;
    Server s(service);
    s.myread();

*/
