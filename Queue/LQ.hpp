//Linked Queue

#ifndef LQ_hpp
#define LQ_hpp

#include <iostream>
using namespace std;
typedef int ElementType;

class Node {
public:
    ElementType data;
    Node * nextNode;
    Node();
    Node(ElementType data);
};

class LQ{
public:
    Node * front;
    Node * rear;
    int Count;
    LQ();
    void EnQueue(ElementType data);
    void EnQueue(Node *newNode);
    Node * DeQueue();
    bool IsEmpty();
    void printQueue();
};
#endif /* LQ_hpp */
