

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include <vector>
using namespace std;

typedef int ElementType;

class HeapNode {
public:
    ElementType data;
    HeapNode(){};
    HeapNode(ElementType data);
};

class Heap{
public:
    int capacity;
    int usedSize;
    vector <HeapNode> nodes;
    Heap();
    Heap(int capacity);
    void insert(ElementType data);
    void deleteMin();
    void printNode();
};
#endif /* Heap_hpp */
