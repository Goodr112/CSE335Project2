#ifndef BUILDBUNDLES_H
#define BUILDBUNDLES_H

#include "builder.h"
#include "bundle.h"
#include "technology.h"

class buildBundles : public Builder {
public:
    virtual std::vector<QString> readFiles();
    std::vector<Bundle*> convertVector(std::vector<QString>, std::vector<Technology*>);
    int calcSavings(Bundle*, std::vector<Technology*>);

private:
    QString name;
    QString price;
    std::vector<QString> items;
};

#endif // BUILDBUNDLES_H
