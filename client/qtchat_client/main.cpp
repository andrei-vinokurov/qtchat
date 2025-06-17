#include "mainwindow.h"
#include <boost/asio.hpp>
#include <QApplication>

int main(int argc, char *argv[])
{
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket(io_service);
    boost::asio::ip::tcp::endpoint endpoint;
    boost::system::error_code ec;
    socket.connect(endpoint, ec);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
