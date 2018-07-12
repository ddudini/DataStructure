
#include "DLL.hpp"

DLL::DLL() {
    Count = 0;
    Head = new Node;
}

DLL::~DLL() {
    delete Head;
}

void DLL::valid(int index){
    if(Count < index){
        throw "Error: Index out of range.";
    }
}

void DLL::add(ElementType data){
    Node * newNode = new Node(data);
    
    if(Head->nextNode == NULL){
        cout << "Head Creared\n";
        Head = newNode;
        Tail = newNode;
        Head->nextNode = Tail;
        Tail->beforeNode = Head;
    }
    else {
        Tail->nextNode = newNode;
        newNode->beforeNode = Tail;
        Tail =newNode;
        cout << "Node Inserted" << endl;
    }
    Count++;
}

void DLL::add(int index, ElementType data){
    try{
        valid(index);
    }
    catch(const char* msg)
    {
        cout << msg << endl;
        return;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    Node * newNode = new Node(data);
    
    if(Current == Tail) Tail = newNode;
    
    newNode->nextNode = Current->nextNode;
    newNode->beforeNode = Current;
    Current->nextNode = newNode;
    Count++;
    
}
void DLL::add(Node * Current, ElementType data){
    Node * newNode = new Node(data);
    
    if(Current == Tail) Tail = newNode;
    
    newNode->nextNode = Current;
    newNode->beforeNode = Current->beforeNode;
    Current->beforeNode = newNode;
    Count++;
    
}
void DLL::set(int index, ElementType data){
    try {
        valid(index);
    }
    catch(const char * msg) {
        cout << msg << endl;
        return;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    Current->data = data;
    
}
void DLL::remove(int index){
    try {
        valid(index);
    }
    catch(const char * msg) {
        cout << msg << endl;
        return;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    Current->nextNode = (Current->nextNode)->nextNode;
    (Current->beforeNode)->nextNode = Current;
    Count--;
}
void DLL::remove(Node * Current){
    if(Current == Head){
        Head = new Node;
        Tail = new Node;
        Current = NULL;
    }
    else {
        Node * Remove = Current;
        if(Remove->beforeNode != NULL)
            (Current->beforeNode)->nextNode = Remove->nextNode;
        if(Remove->nextNode != NULL)
            (Current->nextNode)->nextNode = Remove->beforeNode;
        
        if(Tail == Remove)
            Tail = Remove->beforeNode;
        Current = Remove->beforeNode;
    }
    Count-=1;
    
}

ElementType DLL::get(int index){
    try {
        valid(index);
    }
    catch(const char * msg) {
        cout << msg << endl;
        return -1;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    return Current->data;
}

int DLL::size()
{
    return Count;
}
bool DLL::isEmpty(){
    if(Head->nextNode == NULL){
        return true;
    }
    else
        return false;
}

void DLL::PrintList(){
    Node * Current = Head;
    
    for(int i=1 ; Current != NULL; i++){
        cout << "[" << i << ": " << Current->data << "] ";
        Current = Current->nextNode;
    }
    cout << endl;
}

void DLL::PrintListFromBack(){
    Node * Current = Tail;
    for(int i = Count ; i>0 ; i--){
        cout << "[" << i << ": " << Current->data << "] ";
        Current = Current->beforeNode;
    }
    cout << endl;
}

