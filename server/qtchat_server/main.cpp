#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *parent;
    boost::asio::io_service service;
    std::shared_ptr<server> server1(new server(service));
    MainWindow w(parent, server1);
    w.show();
    return a.exec();
}
