#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *parent;
    boost::asio::io_service service;
    socket_ptr client(new boost::asio::ip::tcp::socket(service));
    MainWindow w(parent, client);
    w.show();
    return a.exec();
}
