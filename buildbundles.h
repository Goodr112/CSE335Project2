#ifndef BUILDBUNDLES_H
#define BUILDBUNDLES_H

#include "builder.h"

class buildBundles : public Builder {
public:
    virtual void readFiles();
};

#endif // BUILDBUNDLES_H
