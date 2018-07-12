

#include "LQ.hpp"

Node::Node(){
    nextNode = NULL;
}
Node::Node(ElementType data){
    Node::data = data;
    nextNode = NULL;
}
LQ::LQ(){
    front = NULL;
    rear = NULL;
    Count = 0;
}

void LQ::EnQueue(ElementType data){
    Node * newNode = new Node(data);
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }
    else {
        rear->nextNode = newNode;
        rear = newNode;
    }
    Count++;
}
void LQ::EnQueue(Node * newNode){
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }
    else {
        rear->nextNode = newNode;
        rear = newNode;
    }
    Count++;
}

Node * LQ::DeQueue(){
    Node * Remove = front;
    if(front->nextNode == NULL) {
        front = NULL;
        rear = NULL;
    }
    else {
        front = front->nextNode;
    }
    Count--;
    return Remove;
}

bool LQ::IsEmpty(){
    if(front == NULL) return true;
    else return false;
}

void LQ::printQueue(){
    Node * Current = front;
    while (Current!= NULL) {
        printf("%d ", Current->data);
        Current = Current->nextNode;
    }
    printf("\n");
}





