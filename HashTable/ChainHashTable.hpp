//
//  ChainHashTable.hpp
//  code of chaining hash table using linked list

#ifndef ChainHashTable_hpp
#define ChainHashTable_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef string KeyType;
typedef string ValueType; 

//Hash Node
class HNode {
public:
    KeyType key;
    ValueType value;
    HNode(){}
    HNode(KeyType k, ValueType v){
        key = k; value = v; next = NULL;};
    HNode * next;
};

//Linked List for hashTable;
class HLL{
public:
    HNode * head;
    HLL();
    bool add(KeyType key, ValueType value);//return false if collision occur
    HNode * find(KeyType key);
    bool isEmpty();
};

//chainint hash table
class CHT{
public:
    int table_size;
    vector <HLL> table;
    CHT(){}
    CHT(int size);
    int hash(KeyType k); /*자릿수 접기 알고리즘*/
    void set(KeyType key, ValueType value);
    ValueType get(KeyType key);
};
#endif /* ChainHashTable_hpp */
