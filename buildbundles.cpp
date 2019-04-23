#include "buildbundles.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDir>
#include <cmath>

std::vector<QString> buildBundles::readFiles() {
    QString path = QDir::currentPath() + "/../CSE335Project2/Bundles.csv";
    QFile file(path);
    QString string;
    QString line;
    QString a;
    std::vector<QString> strings;
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
           a = "";
          line = in.readLine();
          for (auto& i : line) {
              if (i == ',') {
                  strings.push_back(a);
                  a = "";
              } else {
                  a += i;
      }
          }
          strings.push_back(a);
          strings.push_back("xyz");
       }
       file.close();
    }
return strings;
}

int buildBundles::calcSavings(Bundle* b, std::vector<Technology*> vec) {
    double totalPrice = 0.0;
    for (unsigned int i = 0; i < b->getSize(); i++) {
        for (unsigned int j = 0; i < vec.size(); j++) {
            if (b->getItem(i) == vec[j]->getProductName()) {
                totalPrice += vec[j]->getPrice().toDouble();
                break;
            }
        }
    }
    double savings = (b->getPrice().toDouble() / totalPrice) * 100;
    savings = std::round(100-savings);
    return int(savings);
}

std::vector<Bundle*> buildBundles::convertVector(std::vector<QString> vec, std::vector<Technology*> vec2) {
    std::vector<Bundle*> finalVec;
    unsigned int iterator = 0;
    unsigned int numberOfItems = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        if (vec[i] == "xyz") {
            numberOfItems += 1;
        }
    }
    for (unsigned int i = 0; i < numberOfItems; i++) {
        Bundle* bundle = new Bundle();
        bundle->setName(vec[iterator]);
        iterator += 1;
        bundle->setPrice(vec[iterator]);
        iterator += 1;
        while (vec[iterator] != "xyz") {
             bundle->addToVec(vec[iterator]);
             iterator += 1;
            }
        iterator += 1;
        finalVec.push_back(bundle);
    }

    for (unsigned int i = 0; i < finalVec.size(); i++) {
        int save = calcSavings(finalVec[i], vec2);
        finalVec[i]->setSavings(save);
    }
    return finalVec;
}
