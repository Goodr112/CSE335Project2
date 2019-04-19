#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "shoppingcartdialog.h"


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

private:
    Ui::MainWindow *ui;
    std::vector<shoppingCartDialog*> cart;
};

#endif // MAINWINDOW_H
