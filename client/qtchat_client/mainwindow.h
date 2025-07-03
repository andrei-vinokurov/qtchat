#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, socket_ptr client = nullptr);
    ~MainWindow();
    socket_ptr m_client;

private:
    Ui::MainWindow *ui;

private slots:
    void OpenDlg();
};
#endif // MAINWINDOW_H
