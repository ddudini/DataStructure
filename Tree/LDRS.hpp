//
//  LDRS.hpp
//  Tree
//  Lsft Child Right Sibilings

#ifndef LDRS_hpp
#define LDRS_hpp

#include "dataType.hpp"//

class LCRSN{
public:
    int degree;
    ElementType data;
    LCRSN * leftChild;
    LCRSN * RightSibling;
    LCRSN();
    LCRSN(ElementType data);
};

class LCRS{
public:
    int depth;
    LCRSN * root;
    LCRS();
    LCRS(ElementType data);
    LCRS(LCRSN * r);
    void addChild(LCRSN * parent, LCRSN * child);
    void PrintTree();
    void PrintTree(LCRSN * parent, int depth);
    void PrintTreeAtLevel(int level);
    void PrintTreeAtLevel(LCRSN * parent, int depth, int level);
};
#endif /* LDRS_hpp */
