#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cartdialog.h"
#include "buildbundles.h"
#include "buildproducts.h"
#include<vector>
#include<QTableWidgetItem>
#include<iostream>
#include <QtWidgets>
#include <iostream>

#include <QDebug>

#include <QAbstractItemView>

using std::vector;
using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->productsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bundlesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    cart = new CartDialog(this);
    connect(cart, SIGNAL(cartClosed()), this, SLOT(buttonValueShow()));
    connect(cart, SIGNAL(checkout()), this, SLOT(checkoutProcess()));

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

void MainWindow::buttonValueShow() {
    ui->showCart->setText("Show Cart");
}

void MainWindow::checkoutProcess() {
    ui->addToCart->setEnabled(false);
    ui->loadDatabase->setEnabled(false);
}

void MainWindow::actByYourChange(QObject* senderObj) {
    if (senderObj == ui->loadDatabase) {
            buildProducts* bp = new buildProducts();
            std::vector<QString> strings = bp->readFiles();
            std::vector<Technology*> vec = bp->convertVector(strings);
            int iterator_row = 0;
            int column = 0;
            for (unsigned int i = 0; i < vec.size(); i++) {
                ui->productsTable->insertRow(iterator_row);
                QTableWidgetItem* name = new QTableWidgetItem(vec[i]->getProductName());
                ui->productsTable->setItem(iterator_row, column, name);
                column += 1;
                QTableWidgetItem* type = new QTableWidgetItem(vec[i]->getType());
                ui->productsTable->setItem(iterator_row, column, type);
                column += 1;
                QTableWidgetItem* price = new QTableWidgetItem(vec[i]->getPrice());
                ui->productsTable->setItem(iterator_row, column, price);
                column += 1;
                QTableWidgetItem* specialAttribute = new QTableWidgetItem(vec[i]->getAttribute());
                ui->productsTable->setItem(iterator_row, column, specialAttribute);
                column = 0;
                iterator_row += 1;
            }


            buildBundles* bb = new buildBundles();
            std::vector<QString> strings1 = bb->readFiles();
            std::vector<Bundle*> vec1 = bb->convertVector(strings1, vec);
            int iterator_row1 = 0;
            int column1 = 0;
            for (unsigned int i = 0; i < vec1.size(); i++) {
                ui->bundlesTable->insertRow(iterator_row1);
                QTableWidgetItem* name = new QTableWidgetItem(vec1[i]->getName());
                ui->bundlesTable->setItem(iterator_row1, column1, name);
                column1 += 1;
                QTableWidgetItem* price = new QTableWidgetItem(vec1[i]->getPrice());
                ui->bundlesTable->setItem(iterator_row1, column1, price);
                column1 += 1;
                QTableWidgetItem* savings = new QTableWidgetItem(QString::number(vec1[i]->getSavings()) + "%");
                ui->bundlesTable->setItem(iterator_row1, column1, savings);
                iterator_row1 += 1;
                column1 = 0;
                }
            ui->loadDatabase->setEnabled(false);


    } else if (senderObj == ui->addToCart) {
        QModelIndexList productSelection = this->ui->productsTable->selectionModel()->selectedRows();
        vector<Technology*> productsList;
        for(int i=0; i< productSelection.count(); i++) {
            QModelIndex index = productSelection.at(i);
            Technology* newProduct = new Technology();
            newProduct->setPrice(this->ui->productsTable->item(index.row(), 2)->text());
            newProduct->setProductName(this->ui->productsTable->item(index.row(), 0)->text());
            productsList.push_back(newProduct);
        }

        QModelIndexList bundleSelection = this->ui->bundlesTable->selectionModel()->selectedRows();
        vector<Bundle*> bundlesList;
        for(int i=0; i< bundleSelection.count(); i++) {
            QModelIndex index = bundleSelection.at(i);
            Bundle* newBundle = new Bundle();
            newBundle->setPrice(this->ui->bundlesTable->item(index.row(), 1)->text());
            newBundle->setName(this->ui->bundlesTable->item(index.row(), 0)->text());
            bundlesList.push_back(newBundle);
        }

        cart->setProducts(productsList);
        cart->setBundles(bundlesList);

    } else if (senderObj == ui->showCart) {

        if (ui->showCart->text() == "Show Cart") {
            cart->show();
            ui->showCart->setText("Hide Cart");
        } else {
            cart->close();
            ui->showCart->setText("Show Cart");
        }

    }
}

