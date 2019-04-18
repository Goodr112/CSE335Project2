#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void on_addToCart_clicked();

    void on_showCart_clicked();

    void on_loadDatabase_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<shoppingCartDialog*> cart;
};

#endif // MAINWINDOW_H
