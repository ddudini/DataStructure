#ifndef RBT_hpp
#define RBT_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
typedef int ElementType;
enum class Color {red, black};


class RBTNode{
public:
    RBTNode* parent;
    RBTNode* leftchild;
    RBTNode* rightchild;
    ElementType data;
    Color type;
    RBTNode();
    RBTNode(ElementType data, Color type);
    RBTNode(ElementType data, Color type, RBTNode* NILchild);
};

class RBT{
public:
    RBTNode* root;
    RBTNode* NIL;
    RBT();
    RBTNode * searchMinNode(RBTNode * parent);
    RBTNode * search(ElementType data);
    void rotateRight(RBTNode * parent);
    void rotateLeft(RBTNode * parent);
    void insertNode(ElementType data);
    void insertNodeHelper(RBTNode * newNode);
    void rebuildAfterInsert(RBTNode * newNode);
    void preOrder(RBTNode * current);
    RBTNode * deleteNode(ElementType data);
    void rebuildAfterDelte(RBTNode * removed);
};

#endif /* RBT_hpp */
