#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcartdialog.h"
#include "buildbundles.h"
#include "buildproducts.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addToCart_clicked()
{
    if (cart.size() == 0) {
        shoppingCartDialog* scd = new shoppingCartDialog();
        cart.push_back(scd);
    }
    if (cart.size() == 1) {
        cart.front()->show();
        ui->showCart->setText("Hide Cart");
    }
}

void MainWindow::on_showCart_clicked()
{
    if (cart.size() == 0) {
    shoppingCartDialog* scd = new shoppingCartDialog();
    cart.push_back(scd);
    scd->show();
    ui->showCart->setText("Hide Cart");
    return;
    }
    if (ui->showCart->text() == "Show Cart") {
        cart.front()->show();
        ui->showCart->setText("Hide Cart");
    } else {
        cart.front()->close();
        ui->showCart->setText("Show Cart");
    }
}

void MainWindow::on_loadDatabase_clicked()
{
    buildBundles* bb = new buildBundles();
    bb->readFiles();
    //buildProducts* bp = new buildProducts();
    //bp->readFiles();

}
