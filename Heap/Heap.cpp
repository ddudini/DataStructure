

#include "Heap.hpp"

HeapNode::HeapNode(ElementType data){
    HeapNode::data = data;
}

Heap::Heap(){};
Heap::Heap(int capacity){
    Heap::capacity = capacity;
    usedSize = 0;
    nodes = vector <HeapNode>(capacity);
}

void Heap::insert(ElementType data){
    int current = usedSize;
    int parent = (current-1)/2;
    
    if(current == capacity) {
        nodes.resize(capacity*2);
        capacity *=2;
    }
    
    nodes[current].data = data;
    usedSize++;
    while(current > 0 && nodes[current].data < nodes[parent].data){
        if(current > usedSize ) break;
        int temp = nodes[parent].data;
        nodes[parent].data = nodes[current].data;
        nodes[current].data = temp;
        current = parent;
        parent = (current-1) / 2;
    }

    
}

void Heap::deleteMin(){
    int current = 0;
    nodes[current].data = nodes[usedSize-1].data;
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
            selectedChild = nodes[left].data <= nodes[right].data ? left : right;

        if(nodes[selectedChild].data < nodes[current].data) {
            int temp = nodes[selectedChild].data;
            nodes[selectedChild].data = nodes[current].data;
            nodes[current].data = temp;
            current = selectedChild;
        }
        else break;
    }
    
    if(usedSize <= capacity/2){
        capacity /= 2;
        nodes.resize(capacity/2);
    }

}

void Heap::printNode(){
    for(int i=0; i< usedSize ; i++){
        printf("%d ", nodes[i].data);
    }
    printf("\n");
}
