#include "buildbundles.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string>
#include <QTableWidgetItem>
#include <QStringList>


std::vector<QString> buildBundles::readFiles() {
    QFile file("C:/Users/parke/OneDrive/Documents/GitHub/CSE335Project2/Bundles.csv");
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
