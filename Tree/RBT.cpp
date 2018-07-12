
#include "RBT.hpp"
RBTNode::RBTNode(){
    parent = NULL;
    leftchild = NULL;
    rightchild = NULL;
    type = Color::black;
}

RBTNode::RBTNode(ElementType data, Color type){
    parent = NULL;
    leftchild = NULL;
    rightchild = NULL;
    RBTNode::type = type;
    RBTNode::data = data;
}
RBTNode::RBTNode(ElementType data, Color type,RBTNode * NILchild){
    parent = NULL;
    leftchild = NILchild;
    rightchild = NILchild;
    RBTNode::type = type;
    RBTNode::data = data;
}

RBT::RBT(){
    root = NULL;
    NIL = new RBTNode();
}

RBTNode * RBT::search(ElementType data){
    RBTNode * Current = root;
    RBTNode * Match = NULL;
    while(Current != NIL){
        if(Current->data == data){
            Match = Current;
            break;
        }
        
        if(Current->data < data)
            Current = Current->rightchild;
        else if(Current->data > data)
            Current = Current->leftchild;
    }
    
    return Match;
}

void RBT::rotateRight(RBTNode * parent){
    if(parent == NIL) {
        cout << "NIL to rotate right?";
        return;
    }

    RBTNode * left = parent->leftchild;
    
    left->parent = parent->parent;
    if(parent->parent == NULL)
        root = left;
    else {
        if(parent == (parent->parent)->leftchild)
            (parent->parent)->leftchild = left;
        else
            (parent->parent)->rightchild = left;
    }
    
    parent->leftchild = left->rightchild;
    if((left->rightchild) != NIL)
        (left->rightchild)->parent = parent;
    
    parent->parent = left;
    left->rightchild = parent;
    
}

void RBT::rotateLeft(RBTNode * X){
    if(X == NIL) {
        cout << "NIL to rotate left";
        return;
    }
    RBTNode * right = X->rightchild;
    
    if(X->parent == NULL){
        root = X;
    }
    else {
        if(X == (X->parent)->leftchild)
            (X->parent)->leftchild = right;
        else
            (X->parent)->rightchild = right;
    }
    
    X->rightchild = right->leftchild;
    if(right->leftchild != NIL)
        (right->leftchild)->parent = X;
   
    X->parent = right;
    right->leftchild = X;
}

void RBT::insertNode(ElementType data){
    RBTNode * newNode = new RBTNode(data, Color::red, NIL);
    insertNodeHelper(newNode);
    rebuildAfterInsert(newNode);
    
}
void RBT::insertNodeHelper(RBTNode * newNode){
    RBTNode * Current = root;
    
    if(root == NULL){
        root = newNode;
        return;
    }
    
    while(Current != NIL){
        if(Current->data < newNode->data){
            if(Current->rightchild == NIL){
                Current->rightchild = newNode;
                newNode->parent = Current;
                break;
            }
            Current = Current->rightchild;
        }
        else if(Current->data > newNode->data){
            if(Current->leftchild == NIL){
                Current->leftchild = newNode;
                newNode->parent = Current;
                break;
            }
            Current = Current->leftchild;
        }
    }
}

void RBT::rebuildAfterInsert(RBTNode * newNode){
    while(newNode != root && newNode->parent->type == Color::red) {
        RBTNode * parent        = newNode->parent;
        RBTNode * grandParent   = parent->parent;
        RBTNode * Uncle;
        
        if(parent == grandParent->leftchild){
            Uncle = grandParent->rightchild;
            
            if(Uncle->type == Color::red){
                parent->type        = Color::black;
                Uncle->type         = Color::black;
                grandParent->type   = Color::red;
                newNode = grandParent;
            }
            else {
                if(newNode == parent->rightchild){
                    newNode = parent;
                    rotateLeft(newNode);
                    
                }
                parent = newNode->parent;
                grandParent = parent->parent;
                parent->type        = Color::black;
                grandParent->type   = Color::red;
                rotateRight(grandParent);
            }
        }
        else {
            Uncle = grandParent->leftchild;
            
            if(Uncle->type == Color::red){
                parent->type        = Color::black;
                Uncle->type         = Color::black;
                grandParent->type   = Color::red;
                newNode = grandParent;
            }
            else {
                if(newNode == parent->leftchild){
                    newNode = parent;
                    rotateRight(newNode);
                }
                parent = newNode->parent;
                grandParent = parent->parent;
                
                parent->type        = Color::black;
                grandParent->type   = Color::red;
                rotateLeft(grandParent);
                
            }
            
        }
    }
    
    root->type = Color::black;
}

void RBT::preOrder(RBTNode * Current){
    if(Current == NIL) return;
    
    cout << Current->data << " " << (int)Current->type << " | ";
    preOrder(Current->leftchild);
    preOrder(Current->rightchild);
}

RBTNode * RBT::searchMinNode(RBTNode * parent){
    RBTNode * minNode = parent;
    while(minNode->leftchild == NIL) {
        minNode = minNode->leftchild;
    }
    return minNode;
}
RBTNode * RBT::deleteNode(ElementType data){
    RBTNode * target = search(data);
    RBTNode * parent = target->parent;
    
    //leaf Node 삭제
    if(target->leftchild == NIL && target->rightchild == NIL) {
        if(parent->leftchild == target)
            parent->leftchild = NIL;
        else
            parent->rightchild = NIL;
        return target;
    }
    else {
        //자식이 양쪽 다 있는 경우
        if(target->leftchild != NIL && target->rightchild){
            RBTNode * minNode = searchMinNode(target);
            int temp = minNode->data;
            deleteNode(minNode->data);
            target->data = temp;
            
        }
        // 자식이 한쪽 만 있는 경우
        else {
            if(target->rightchild != NIL){
                if(parent->leftchild == NIL)
                    parent->leftchild = target->rightchild;
                else
                    parent->rightchild = target->rightchild;
            }
            else {
                if(parent->leftchild == NIL)
                    parent->leftchild = target->leftchild;
                else
                    parent->rightchild = target->leftchild;
            }
        }
        
        
    }
    
    return target;
    
}

