#include "cartdialog.h"
#include "ui_cartdialog.h"
#include "cartvisitor.h"

#include <QDebug>

#include <iostream>
using std::cout;
using std::endl;

CartDialog::CartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CartDialog)
{
    ui->setupUi(this);

    ui->cartTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->cartTable->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->totalPriceLabel->setStyleSheet("QLabel { color: red; }");
}

CartDialog::~CartDialog()
{
    delete ui;
}

void CartDialog::setProducts(vector<Technology*> p) {
    for (unsigned int i=0; i < p.size(); i++)
        products.push_back(p[i]);

    int iterator_row = 0;
    int column = 0;
    for (unsigned int i = 0; i < p.size(); i++) {
        ui->cartTable->insertRow(iterator_row);
        QTableWidgetItem* name = new QTableWidgetItem(p[i]->getProductName());
        ui->cartTable->setItem(iterator_row, column, name);
        column += 1;
        QTableWidgetItem* type = new QTableWidgetItem(p[i]->getPrice());
        ui->cartTable->setItem(iterator_row, column, type);
        column = 0;
        iterator_row += 1;
    }
}

void CartDialog::setBundles(vector<Bundle*> b) {
    for (unsigned int i=0; i < b.size(); i++)
        bundles.push_back(b[i]);

    int iterator_row = 0;
    int column = 0;
    for (unsigned int i = 0; i < b.size(); i++) {
        ui->cartTable->insertRow(iterator_row);
        QTableWidgetItem* name = new QTableWidgetItem(b[i]->getName());
        ui->cartTable->setItem(iterator_row, column, name);
        column += 1;
        QTableWidgetItem* type = new QTableWidgetItem(b[i]->getPrice());
        ui->cartTable->setItem(iterator_row, column, type);
        column = 0;
        iterator_row += 1;
    }
}

void CartDialog::on_deleteButton_clicked() {
    QModelIndexList selection = this->ui->cartTable->selectionModel()->selectedRows();
    for(int i=0; i< selection.count(); i++) {
        QModelIndex index = selection.at(i);
        int row = index.row();
        QString name = ui->cartTable->item(row, 0)->text();

        vector<Technology*>::iterator productItr = std::find_if(products.begin(), products.end(), [&](Technology* p) {
            return p->getProductName() == name;
        });
        if (productItr != products.end()) {
            products.erase(productItr);
            ui->cartTable->removeRow(row);
        }

        vector<Bundle*>::iterator bundleItr = std::find_if(bundles.begin(), bundles.end(), [&](Bundle* b) {
            return b->getName() == name;
        });
        if (bundleItr != bundles.end()) {
            bundles.erase(bundleItr);
            ui->cartTable->removeRow(row);
        }
    }
}

void CartDialog::on_checkoutButton_clicked() {
    CartVisitor cv;

    for (unsigned int i=0; i < products.size(); i++) {
        products[i]->Accept(&cv);
    }
    for (unsigned int i=0; i < bundles.size(); i++) {
        bundles[i]->Accept(&cv);
    }

    QString totalPrice = "TOTAL: $" + QString::number(cv.getTotalPrice());

    ui->totalPriceLabel->setText(totalPrice);

    ui->deleteButton->setEnabled(false);
    ui->checkoutButton->setEnabled(false);

    emit checkout();
}

void CartDialog::on_CartDialog_finished(int) {
    emit cartClosed();
}
