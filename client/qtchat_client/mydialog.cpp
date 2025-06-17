#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags().setFlag(Qt::WindowContextHelpButtonHint, false));
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(SendText()));
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::SendText()
{
    ui->plainTextEdit_2->appendPlainText(ui->plainTextEdit->toPlainText());
    ui->plainTextEdit->setPlainText("");
    ui->plainTextEdit->setFocus();
}
