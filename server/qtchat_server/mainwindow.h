#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, std::shared_ptr<server> serv = nullptr);
    ~MainWindow();
    //boost::asio::io_service m_service;
    std::shared_ptr<server> m_server;


private:
    Ui::MainWindow *ui;

private slots:
    void listen();

};
#endif // MAINWINDOW_H
