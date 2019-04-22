#include "buildproducts.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QDir>

std::vector<QString> buildProducts::readFiles() {
    QString path = QDir::currentPath() + "/../CSE335Project2/Technology.csv";
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
       }
       file.close();
    }
return strings;
}

std::vector<Technology*> buildProducts::convertVector(std::vector<QString> vec) {
    std::vector<Technology*> finalVec;
    for (unsigned int i = 0; i < vec.size(); i+=6) {
        Technology* tech = new Technology();
        tech->setProductName(vec[i+1]);
        tech->setType(vec[i]);
        tech->setPrice(vec[i+4]);
        tech->setAttribute(vec[i+5]);
        finalVec.push_back(tech);
    }
    return finalVec;
}
