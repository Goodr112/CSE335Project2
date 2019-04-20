#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcartdialog.h"
#include "buildbundles.h"
#include "buildproducts.h"
#include<vector>
#include<QTableWidgetItem>
#include<iostream>
#include <QtWidgets>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loadDatabase, SIGNAL(clicked()), ui->loadDatabase, SLOT(myStateChanged()));
    connect(ui->loadDatabase, SIGNAL(iChanged(QObject*)), this, SLOT(actByYourChange(QObject*)));

    connect(ui->addToCart, SIGNAL(clicked()), ui->addToCart, SLOT(myStateChanged()));
    connect(ui->addToCart, SIGNAL(iChanged(QObject*)), this, SLOT(actByYourChange(QObject*)));

    connect(ui->showCart, SIGNAL(clicked()), ui->showCart, SLOT(myStateChanged()));
    connect(ui->showCart, SIGNAL(iChanged(QObject*)), this, SLOT(actByYourChange(QObject*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actByYourChange(QObject* senderObj) {
    if (senderObj == ui->loadDatabase) {
        /*
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
            std::vector<Technology*> vec = bp->convertVector(strings);
            int iterator_row = 0;
            int column = 0;
            for (unsigned int i = 0; i < vec.size(); i++) {
                ui->productsTable->insertRow(iterator_row);
                QTableWidgetItem* item = new QTableWidgetItem(vec[i]->getProductName());
                ui->productsTable->setItem(iterator_row, column, item);
                column += 1;
                QTableWidgetItem* item2 = new QTableWidgetItem(vec[i]->getType());
                ui->productsTable->setItem(iterator_row, column, item2);
                column += 1;
                QTableWidgetItem* item3 = new QTableWidgetItem(vec[i]->getPrice());
                ui->productsTable->setItem(iterator_row, column, item3);
                column += 1;
                QTableWidgetItem* item4 = new QTableWidgetItem(vec[i]->getAttribute());
                ui->productsTable->setItem(iterator_row, column, item4);
                column = 0;
                iterator_row += 1;

                //ui->loadDatabase->setEnabled(false);
            }


    } else if (senderObj == ui->addToCart) {
        if (cart.size() == 0) {
            shoppingCartDialog* scd = new shoppingCartDialog();
            cart.push_back(scd);
        }
        if (cart.size() == 1) {
            cart.front()->show();
            ui->showCart->setText("Hide Cart");
        }

    } else if (senderObj == ui->showCart) {
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
}
