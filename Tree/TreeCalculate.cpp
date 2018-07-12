//
//  TreeCalculate.cpp
//  Tree
//
//  Created by Sujin Han on 2018. 7. 6..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include "TreeCalculate.hpp"

TreeCalculator::TreeCalculator(){}
TreeCalculator::TreeCalculator(string s){
    postfomula = s;
    fomulaTree = BT();
    fomulaTree.root = new BTNode();
    
    int * len = new int();
    *len = postfomula.size()-1;
    changeToTree(len, fomulaTree.root);
    
}
void TreeCalculator::changeToTree(int * index, BTNode * Current){
    if(*index < 0) return;
    char op = postfomula[*index];
    (*index)--;
    
    switch (op) {
        case '+': case '-': case '*': case '/':
            Current->data = op;
            Current->leftChild = new BTNode();
            Current->rightChild = new BTNode();
            changeToTree(index, Current->rightChild);
            changeToTree(index, Current->leftChild);
            break;
        default:
            Current->data = op;
            break;
    }
    
}
void TreeCalculator::preOrder(){
    fomulaTree.inorder();
}
double TreeCalculator::calculate(){
    return calculate(fomulaTree.root);
}
double TreeCalculator::calculate(BTNode * Current){
    double left;
    double right;
    double result=0;
    switch (Current->data) {
        case '+': case '-': case '*': case '/':
            left = calculate(Current->leftChild);
            right = calculate(Current->rightChild);
            switch (Current->data) {
                case '+': result = left +  right; break;
                case '-': result = left -  right; break;
                case '*': result = left *  right; break;
                case '/': result = left /  right; break;
            }
            break;
        default:
            char Temp[2];
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Current->data;
            result = atof(Temp);
            break;
    }
    return result;
}
