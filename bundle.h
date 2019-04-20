#ifndef BUNDLE_H
#define BUNDLE_H

#include<vector>
#include <QString>
#include "technology.h"


class Bundle
{
public:
    QString getName() {
        return name;
    }
    QString getPrice() {
        return price;
    }
    void setName(QString q) {
        name = q;
    }
    void setPrice(QString q) {
        price = q;
    }
    int calcSavings();
private:
    QString name;
    QString price;
    std::vector<Technology*> items;

};

#endif // BUNDLE_H
