#ifndef CARTVISITOR_H
#define CARTVISITOR_H

#include "visitor.h"
#include "technology.h"
#include "bundle.h"

class CartVisitor: public Visitor {
public:
    CartVisitor();
    virtual ~CartVisitor(){}
    void visitBundle(Bundle* b);
    void visitProduct(Technology* p);
    double getTotalPrice() const { return totalPrice; }
private:
    double totalPrice;
};

#endif // CARTVISITOR_H
