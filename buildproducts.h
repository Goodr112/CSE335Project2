#ifndef BUILDPRODUCTS_H
#define BUILDPRODUCTS_H

#include "builder.h"
#include "technology.h"

class buildProducts : public Builder {
public:
    virtual std::vector<QString> readFiles();
    virtual std::vector<Technology*> convertVector(std::vector<QString>);
};

#endif // BUILDPRODUCTS_H
