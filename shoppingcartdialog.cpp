#include "shoppingcartdialog.h"
#include "ui_shoppingcartdialog.h"

shoppingCartDialog::shoppingCartDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shoppingCartDialog)
{
    ui->setupUi(this);
}

shoppingCartDialog::~shoppingCartDialog()
{
    delete ui;
}
