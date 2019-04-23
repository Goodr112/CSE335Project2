#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "cartdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void actByYourChange(QObject*);
    void buttonValueShow();
    void checkoutProcess();

private:
    Ui::MainWindow *ui;
    CartDialog* cart;
    unsigned int cartID;
};

#endif // MAINWINDOW_H
