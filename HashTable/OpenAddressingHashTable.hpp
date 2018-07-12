//
//  OpenAddressingHashTable.hpp
//  Data Structure
//  이중 해싱 기반 해쉬 테이블

#ifndef OpenAddressingHashTable_hpp
#define OpenAddressingHashTable_hpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string KeyType;
typedef string ValueType;
enum Status { EMPTY, OCCUPIED};
class ONode{
public:
    KeyType key;
    ValueType value;
    enum Status state;
    
    ONode(){state = EMPTY;};
    ONode(KeyType k, ValueType v, Status s);
    void set(KeyType k, ValueType v, Status s);
};

class OAHT{
public:
    int tableSize;
    vector <ONode*> table;
    int occupiedNum;
    
    OAHT(){};
    OAHT(int size);
    int hash(KeyType key);
    int hash2(KeyType key);
    void set(KeyType key, ValueType value);
    ValueType get(KeyType key);
    void rehash();
    
};

#endif /* OpenAddressingHashTable_hpp */
