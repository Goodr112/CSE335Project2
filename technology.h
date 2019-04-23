#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include <QString>

#include "visitor.h"

class Technology
{

public:
    void Accept(Visitor* v) {
        v->visitProduct(this);
    }

    QString getProductName() {
        return productName;
    }
    QString getType() {
        return type;
    }
    QString getPrice() {
        return price;
    }
    QString getAttribute() {
        return attribute;
    }
    void setProductName(QString name) {
        productName = name;
    }
    void setType(QString type2) {
        type = type2;
    }
    void setPrice(QString p) {
        price = p;
    }
    void setAttribute(QString att) {
        attribute = att;
    }
private:
    QString productName;
    QString type;
    QString price;
    QString attribute;
};

#endif // TECHNOLOGY_H
