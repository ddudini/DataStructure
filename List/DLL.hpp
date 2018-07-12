#ifndef DLL_hpp
#define DLL_hpp

#include <iostream>
using namespace std;
typedef int ElementType;

class Node{
public:
    ElementType data;
    Node * nextNode;
    Node * beforeNode;
    Node() {
        beforeNode = NULL;
        nextNode = NULL;}
    Node(ElementType data) {
        Node::data = data;
        nextNode = NULL;
        beforeNode = NULL;
    }
    void PrintNode(){
        cout << data << " ";
    }
};

//Class definition of doubly linked list
class DLL {
public:
    int Count;
    Node * Head;
    Node * Tail;
    DLL();
    ~DLL();
    void valid(int index);
    void add(ElementType data);
    void add(int index, ElementType data);
    void add(Node * Current, ElementType data);
    void set(int index, ElementType data);
    void remove(int index);
    void remove(Node * Current);
    Node * top();
    ElementType get(int index);
    int size();
    bool isEmpty();
    void PrintList();
    void PrintListFromBack();
    void sort(); //sort DLL using quick sort.
};

#endif /* DLL_hpp */
