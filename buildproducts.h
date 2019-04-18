#ifndef BUILDPRODUCTS_H
#define BUILDPRODUCTS_H

#include "builder.h"

class buildProducts : public Builder {
public:
    virtual void readFiles();
};

#endif // BUILDPRODUCTS_H
