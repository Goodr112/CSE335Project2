#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcartdialog.h"
#include "buildbundles.h"
#include "buildproducts.h"
#include<vector>
#include<QTableWidgetItem>
#include<iostream>
#include <QtWidgets>

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
{/*
    std::vector<QString> strings;
    buildBundles* bb = new buildBundles();
    strings = bb->readFiles();
    int iterator = 0;
    int column = 0;
    for (int i = 0; i < strings.size(); i++) {
        QTableWidgetItem* item = new QTableWidgetItem(strings[i]);
        if (i == 0) {
            ui->bundlesTable->insertRow(iterator);
            column = 0;
            item->setText(strings[i]);
            ui->bundlesTable->setItem(iterator, column, item);
            iterator += 1;
            column += 1;
            ui->bundlesTable->show();
        } else {
    item->setText(strings[i]);
    ui->bundlesTable->setItem(iterator, column, item);
    column += 1;
    ui->bundlesTable->show();
    }
    }*/


    buildProducts* bp = new buildProducts();
    std::vector<QString> strings = bp->readFiles();
    int iterator_row = 0;
    int column = 0;
    for (unsigned int i = 0; i < strings.size(); i++) {
        QTableWidgetItem* item = ui->productsTable->item(iterator_row, column);
        item = new QTableWidgetItem();
        if (i == 5 || (i % 5 == 1 && i > 6)) {
            ui->productsTable->insertRow(iterator_row);
            iterator_row += 1;
            column = 0;
        }
        if (i < 6) {
        ui->productsTable->insertColumn(column);
        }
        ui->productsTable->setItem(iterator_row, column, item);
        item->setText(strings[i]);
        column += 1;
    }

    ui->loadDatabase->setEnabled(false);
}
