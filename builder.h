#ifndef BUILDER_H
#define BUILDER_H

#include<iostream>
#include<vector>
#include <Qstring>
#include "technology.h"


class Builder{
public:
    virtual std::vector<QString> readFiles() = 0;
};

#endif // BUILDER_H
