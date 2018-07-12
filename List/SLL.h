

#ifndef SLL_h
#define SLL_h
#include <iostream>
using namespace std;
typedef int ElementType;

class Node{
public:
    ElementType data;
    Node * nextNode;
    Node() {nextNode = NULL;}
    Node(ElementType data) {
        Node::data = data;
        nextNode = NULL;
    }
    void PrintNode(){
        cout << data << " ";
    }
};

//Class definition of singly linked list
class SLL {
public:
    int Count;
    Node * Head;
    SLL();
    ~SLL();
    void valid(int index);
    void add(ElementType data);
    void add(int index, ElementType data);
    void set(int index, ElementType data);
    void remove(int index);
    ElementType get(int index);
    int size();
    bool isEmpty();
    void PrintList();
};

#endif /* SLL_h */
