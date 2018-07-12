
#ifndef LLS_hpp
#define LLS_hpp

#include <iostream>
using namespace std;
typedef int ElementType;

class Node {
public:
    ElementType data;
    Node * nextNode;
    Node (){
        nextNode = NULL;
    }
    Node (ElementType data){
        Node::data = data;
        nextNode = NULL;
    }
};

//linked list stack

class LLS{
public:
    int Count;
    Node * bottom;
    Node * top;
    LLS();
    ElementType pop();
    void valid();
    void push(ElementType data);
    int size();
    ElementType getTop();
    bool isEmpty();
    void printList();
};

#endif /* LLS_hpp */
