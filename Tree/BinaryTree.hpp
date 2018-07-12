//
//  BinaryTree.hpp
//  Tree
//
//  Created by Sujin Han on 2018. 7. 2..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "dataType.hpp"

class BTNode{
public:
    ElementType data;
    BTNode * leftChild;
    BTNode * rightChild;
    BTNode();
    BTNode(ElementType data);
};

//binary tree definition
class BT{
public:
    BTNode * root;
    BT();
    BT(ElementType data);
    BT(BTNode * root);
    void add(ElementType data);
    void add(BTNode * parent, BTNode * newNode);
    void preorder();
    void preorder(BTNode * parent);
    void postorder();
    void postorder(BTNode * parent);
    void inorder();
    void inorder(BTNode * parent);
    BTNode * get(ElementType data);
    void erase(ElementType data);
    
};
#endif /* BinaryTree_hpp */
