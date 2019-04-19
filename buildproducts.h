#ifndef BUILDPRODUCTS_H
#define BUILDPRODUCTS_H

#include "builder.h"

class buildProducts : public Builder {
public:
    virtual std::vector<QString> readFiles();
};

#endif // BUILDPRODUCTS_H
