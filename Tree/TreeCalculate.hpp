#ifndef TreeCalculate_hpp
#define TreeCalculate_hpp

#include "BinaryTree.hpp"

class TreeCalculator {
public:
    string postfomula;
    BT fomulaTree;
    TreeCalculator();
    TreeCalculator(string s);
    void changeToTree(int * index, BTNode * Current);
    void preOrder();
    double calculate();
    double calculate(BTNode * Current);
};

#endif /* TreeCalculate_hpp */
