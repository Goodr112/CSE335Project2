#ifndef CARTDIALOG_H
#define CARTDIALOG_H

#include <QDialog>
#include <QModelIndexList>

#include <vector>
using std::vector;

#include "bundle.h"
#include "technology.h"

namespace Ui {
class CartDialog;
}

class CartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CartDialog(QWidget *parent = nullptr);
    ~CartDialog();
    Ui::CartDialog* getUi() const { return ui; }
    void setProducts(vector<Technology*>);
    void setBundles(vector<Bundle*>);
signals:
    void cartClosed();
    void checkout();

private slots:
    void on_deleteButton_clicked();
    void on_checkoutButton_clicked();
    void on_CartDialog_finished(int result);

private:
    Ui::CartDialog *ui;
    vector<Technology*> products;
    vector<Bundle*> bundles;
};

#endif // CARTDIALOG_H
