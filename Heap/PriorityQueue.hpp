
#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <stdio.h>
#include <vector>
using namespace std;

typedef int Priority;

class PQNode {
public:
    Priority priority;
    void * data;
    PQNode(){};
    PQNode(Priority p, void * data);
    void set(Priority p, void * d);
};

class PQ{
public:
    int capacity;
    int usedSize;
    vector <PQNode> nodes;
    PQ();
    PQ(int capacity);
    void PQ_enqueue(Priority p, void * data);
    void PQ_dequeue();
    void printNode();
};


#endif /* PriorityQueue_hpp */
