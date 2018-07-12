#include "BinaryTree.hpp"

BTNode::BTNode(){
    leftChild = NULL;
    rightChild = NULL;
}
BTNode::BTNode(ElementType data){
    BTNode::data = data;
    BTNode::leftChild = NULL;
    BTNode::rightChild = NULL;
}
BT::BT(){
    root = NULL;
}
BT::BT(ElementType data){
    root = new BTNode(data);
}
BT::BT(BTNode * root){
    BT::root = root;
}

void BT::add(ElementType data){
    BTNode * newNode = new BTNode(data);
    add(root, newNode);
}

void BT::add(BTNode * parent, BTNode * newNode){
    cout << parent->data << " " << newNode->data << " ";
    if(parent->data < newNode->data){
        if(parent->rightChild == NULL) {
            cout << "Right Inserted\n";
            parent->rightChild = newNode;
            return;
        }
        else {
            cout << "Right" << endl;
            add(parent->rightChild, newNode);
        }
    }
    else if(parent->data > newNode->data){
        if(parent->leftChild == NULL){
            cout << "Left Inserted" << endl;
            parent->leftChild = newNode;
            return;
        }
        else {
            cout << "Left" << endl;
            add(parent->leftChild, newNode);
        }
        
    }
    else {
        cout <<"redundent data\n";
        return;
    }
}
void BT::preorder(){
    preorder(root);
    cout << endl;
}
void BT::preorder(BTNode * parent){
    if(parent == NULL) return;
    cout << parent->data << " ";
    preorder(parent->leftChild);
    preorder(parent->rightChild);
}

void BT::postorder(){
    postorder(root);
    cout << endl;
}
void BT::postorder(BTNode * parent){
    if(parent == NULL) return;
    postorder(parent->leftChild);
    postorder(parent->rightChild);
    cout << parent->data << " ";
}
void BT::inorder(){
    inorder(root);
    cout << endl;
}
void BT::inorder(BTNode * parent){
    if(parent == NULL) return;
    inorder(parent->leftChild);
    cout << parent->data << " ";
    inorder(parent->rightChild);
}

BTNode * BT::get(ElementType data){
    BTNode * Current = root;
    while (Current->data != data) {
        if(Current->data < data) Current = Current->rightChild;
        else if (Current->data > data) Current = Current ->leftChild;
        
        if(Current == NULL) {
            cout<< "No Matching data";
            break;
        }
    }
    return Current;
}





