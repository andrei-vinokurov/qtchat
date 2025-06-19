#include "client.h"


client::client(boost::asio::io_service &service) : m_sock(service)
{
    boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 2001);
    m_sock.async_connect(ep, boost::bind(&client::connect_handler, this, boost::placeholders::_1));
    service.run();
}

void client::connect_handler(const boost::system::error_code & ec)
{

    if(!ec)
    {
        std::cout << "All right!!!" << std::endl;
        //system("PAUSE");
    }

}

void client::on_write(char * ptr, const boost::system::error_code & err)
{
    delete[] ptr;
}

void client::mywrite()
{
    char * buff = new char[512];
    std::string str = "Andrei Vinokurov";
    for(int i = 0; i <= str.length(); i++) *(buff + i) = str[i];
    m_sock.async_send(boost::asio::buffer(buff, 512), boost::bind(&client::on_write, this, buff, boost::placeholders::_1));
    std::cout << buff << std::endl;
}



/*

boost::asio::io_service io_service;
client a(io_service);
a.mywrite();

*/
