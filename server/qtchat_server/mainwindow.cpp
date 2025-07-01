#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, socket_ptr server)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_server(server)
{
    ui->setupUi(this);
    //boost::asio::io_service service;
    //m_server(service);
    connect(ui->action, SIGNAL(triggered(bool)), this, SLOT(listen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listen()
{
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("Andrew"));
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(0, 0, newItem);

}
