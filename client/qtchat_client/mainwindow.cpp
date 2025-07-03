#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent, socket_ptr client)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_client(client)
{
    ui->setupUi(this);
    connect(ui->action,SIGNAL(triggered()),this,SLOT(OpenDlg()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenDlg()
{
    MyDialog *myDlg = new MyDialog(this);

    myDlg->open();
}
