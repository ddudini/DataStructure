
#include "PriorityQueue.hpp"

PQNode::PQNode(Priority p, void * data){
    PQNode::data = data;
    priority = p;
}
void PQNode::set(Priority p, void * d){
    data = d;
    priority = p;
}

PQ::PQ(){};
PQ::PQ(int capacity){
    PQ::capacity = capacity;
    usedSize = 0;
    nodes = vector <PQNode>(capacity);
}

void PQ::PQ_enqueue(Priority p, void * data){
    int current = usedSize;
    int parent = (current-1)/2;
    
    if(current == capacity) {
        nodes.resize(capacity*2);
        capacity *=2;
    }
    
    nodes[current].set(p, data);
    usedSize++;
    while(current > 0 && nodes[current].priority < nodes[parent].priority){
        if(current > usedSize ) break;
        PQNode temp = nodes[parent];
        nodes[parent]= nodes[current];
        nodes[current]= temp;
        current = parent;
        parent = (current-1) / 2;
    }
    
    
}

void PQ::PQ_dequeue(){
    int current = 0;
    nodes[current] = nodes[usedSize-1];
    usedSize--;
    while(current < usedSize){
        int left = 2*current + 1;
        int right = 2*current + 2;
        int selectedChild;
        
        if(left >= usedSize)
            break;
        if(right >= usedSize)
            selectedChild = left;
        else
            selectedChild = nodes[left].priority <= nodes[right].priority ? left : right;
        
        if(nodes[selectedChild].priority < nodes[current].priority) {
            PQNode temp = nodes[selectedChild];
            nodes[selectedChild] = nodes[current];
            nodes[current] = temp;
            current = selectedChild;
        }
        else break;
    }
    
    if(usedSize <= capacity/2){
        capacity /= 2;
        nodes.resize(capacity/2);
    }
    
}

void PQ::printNode(){
    for(int i=0; i< usedSize ; i++){
        printf("(%d)", nodes[i].priority);
    }
    printf("\n");
}
