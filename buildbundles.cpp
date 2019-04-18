#include "buildbundles.h"
#include <QFile>
#include <QTextStream>
#include <iostream>


void buildBundles::readFiles() {
    QFile file("C:/Users/parke/OneDrive/Documents/GitHub/CSE335Project2/Bundles.csv");
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          std::string a = line.toLocal8Bit().constData();
          std::cout << a << endl;

       }
       file.close();
    }
}
