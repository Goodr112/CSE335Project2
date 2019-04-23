#ifndef VISITOR_H
#define VISITOR_H

class Bundle;
class Technology;

class Visitor
{
public:
    Visitor(){}
    virtual void visitBundle(Bundle* b)=0;
    virtual void visitProduct(Technology* p)=0;
};

#endif // VISITOR_H
