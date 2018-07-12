//
//  LDRS.cpp
//  Tree
//
//  Created by Sujin Han on 2018. 7. 2..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include "LDRS.hpp"

LCRSN::LCRSN() {
    leftChild = NULL;
    RightSibling = NULL;
    degree = 0;
}

LCRSN::LCRSN(ElementType data){
    degree = 0;
    LCRSN::data = data;
    leftChild = NULL;
    RightSibling = NULL;
}
LCRS::LCRS(){
    depth = 0;
    root = NULL;
}
LCRS::LCRS(ElementType data){
    depth = 0;
    root = new LCRSN(data);
}
LCRS::LCRS(LCRSN * r){
    depth = 0;
    root = r;
}

void LCRS::addChild(LCRSN *parent, LCRSN *child){
    if(parent->leftChild == NULL){
        parent->leftChild = child;
        depth++;
    }
    else {
        LCRSN * c = parent->leftChild;
        while(c->RightSibling != NULL){
            c = c->RightSibling;
        }
        c->RightSibling = child;
    }
    parent->degree++;
}

void LCRS::PrintTree(){
    PrintTree(root, 0);
}

void LCRS::PrintTree(LCRSN * parent, int depth){
    if(depth == LCRS::depth+1) return;
    
    for(int i=0 ; i < depth ; i++)
        cout << " ";
    
    if(parent != NULL) cout << parent->data << endl;
    if(parent->leftChild != NULL) PrintTree(parent->leftChild, depth+1);
    if(parent->RightSibling != NULL) PrintTree(parent->RightSibling, depth);
}
void LCRS::PrintTreeAtLevel(int level){
    PrintTreeAtLevel(root,0, level);
}
void LCRS::PrintTreeAtLevel(LCRSN * parent, int depth, int level){
    if(depth+1 > level) return;
    if(level == depth+1 && parent != NULL) cout << parent->data << endl;
    if(parent->leftChild != NULL) PrintTreeAtLevel(parent->leftChild, depth+1, level);
    if(parent->RightSibling != NULL) PrintTreeAtLevel(parent->RightSibling, depth, level);
}








