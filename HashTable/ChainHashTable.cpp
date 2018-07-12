

#include "ChainHashTable.hpp"
CHT::CHT(int size){
    table_size = size;
    table.resize(size);
}

int CHT::hash(KeyType k){
    int hashValue = 0;
    for(int i=0 ; i <k.size(); i++){
        hashValue = (hashValue << 3 ) + k[i];
    }
    hashValue = hashValue % table_size;
    return hashValue;
}

HLL::HLL(){
    head = NULL;
}

bool HLL::add(KeyType key, ValueType value){
    HNode * newNode =  new HNode(key, value);
    if(head == NULL){
        head = newNode;
        return true;
    }
    
    HNode * current = head;
    while(head->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return false;
}
HNode* HLL::find(KeyType key){
    HNode * current = head;
    while(current->key != key){
        current=current->next;
    }
    return current;
}
void CHT::set(KeyType key, ValueType value){
    int address = hash(key);
    bool flag = table[address].add(key, value);
    if(!flag)
        cout << "collision occured at address " << address << ",key " << key << endl;
}
bool HLL::isEmpty(){
    if(head == NULL)
        return true;
    else return false;
}

ValueType CHT::get(KeyType key){
    int address = hash(key);
    if(table[address].isEmpty())
        return NULL;
    return (table[address].find(key))->value;
}
