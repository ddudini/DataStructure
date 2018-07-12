//Linked List Stack
#include "LLS.hpp"
#include <iostream>

LLS::LLS(){
    Count = 0;
    bottom = NULL;
    top = NULL;
}
void LLS::valid(){
    if(isEmpty()){
        throw "stack is Empty";
    }
}
ElementType LLS::pop(){
    try{
        valid();
    }
    catch(const char * msg){
        cout << msg << endl;
        return -1;
    }
    
    Node * OldTop = top;
    if(bottom == top){
        bottom = NULL;
        top = NULL;
    }
    else {
        Node * Current = bottom;
        while(Current->nextNode != top && Current != NULL){
            Current = Current->nextNode;
        }
        top = Current;
        Current->nextNode = NULL;
    }
    return OldTop->data;
}
void LLS::push(ElementType data){
    Node * newNode = new Node(data);
    
    if(bottom == NULL){
        bottom = newNode;
    }
    else {
        Node * Current = bottom;
        while(Current->nextNode != NULL){
            Current = Current->nextNode;
        }
        Current->nextNode = newNode;
    }
    top = newNode;
    Count++;
}
int LLS::size(){
    return Count;
}
ElementType LLS::getTop(){
    try{
        valid();
    }
    catch(const char * msg){
        cout << msg << endl;
        return -1;
    }
    
    return top->data;
}
bool LLS::isEmpty(){
    if(Count == 0){
        return true;
    }
    else return false;
}
void LLS::printList(){
    Node * Current = bottom;
    for(int i=0 ; Current != NULL ; i++){
        cout << "[" << i << " : " << Current->data << "] ";
        Current = Current->nextNode;
    }
    std::cout << std::endl;
}

