#ifndef BUNDLE_H
#define BUNDLE_H

#include<vector>
#include <QString>
#include "technology.h"


class Bundle
{
public:
    Bundle();
public:
    QString getName();
    QString getPrice();
    int calcSavings();
private:
    QString name;
    QString price;
    std::vector<Technology*> items;

};

#endif // BUNDLE_H
