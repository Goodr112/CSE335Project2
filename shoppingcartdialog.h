#ifndef SHOPPINGCARTDIALOG_H
#define SHOPPINGCARTDIALOG_H

#include <QMainWindow>

namespace Ui {
class shoppingCartDialog;
}

class shoppingCartDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit shoppingCartDialog(QWidget *parent = nullptr);
    ~shoppingCartDialog();

private:
    Ui::shoppingCartDialog *ui;
};

#endif // SHOPPINGCARTDIALOG_H
