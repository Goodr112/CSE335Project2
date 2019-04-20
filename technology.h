#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include <QString>


class Technology
{
public:
    Technology();

public:
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
private:
    QString productName;
    QString type;
    QString price;
    QString attribute;
};

#endif // TECHNOLOGY_H
