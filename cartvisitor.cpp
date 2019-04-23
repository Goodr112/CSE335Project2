#include "cartvisitor.h"

CartVisitor::CartVisitor() {
    totalPrice = 0.0;
}

void CartVisitor::visitBundle(Bundle* b) {
    totalPrice += b->getPrice().toDouble();
}

void CartVisitor::visitProduct(Technology* p) {
    totalPrice += p->getPrice().toDouble();
}
