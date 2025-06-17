#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
