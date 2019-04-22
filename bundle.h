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
    void addToVec(QString tech) {
        items.push_back(tech);
    }
    unsigned int getSize() {
        return items.size();
    }
    QString getItem(unsigned int position) {
        return items[position];
    }
    void setSavings(int d) {
        savings = d;
    }
    int getSavings() {
        return savings;
    }
private:
    QString name;
    QString price;
    int savings;
    std::vector<QString> items;

};

#endif // BUNDLE_H
