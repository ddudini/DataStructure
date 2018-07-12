
#include "OpenAddressingHashTable.hpp"

ONode::ONode(KeyType k, ValueType v, Status s){
    key = k;
    value = v;
    s = s;
}
void ONode::set(KeyType k, ValueType v, Status s){
    key = k;
    value = v;
    s = s;
}

OAHT::OAHT(int size){
    tableSize = size;
    table.resize(size, NULL);
    occupiedNum = 0;
}
int OAHT::hash(KeyType key){
    int hashValue = 0;
    for(int i=0 ; i < key.size(); i++)
        hashValue = (hashValue << 3) + key[i];
    return hashValue%tableSize;
}
int OAHT::hash2(KeyType key){
    int hashValue= 0;
    for(int i=0 ; i < key.size(); i++)
        hashValue = (hashValue << 2) + key[i];
    return hashValue % (tableSize-3) + 1;
}
void OAHT::rehash(){
    vector <ONode *> newTable = vector<ONode*>(tableSize * 2, NULL);
    tableSize = tableSize *2;
    for(int i = 0 ; i < tableSize/2 ; i++){
        if(table[i]!= NULL){
            int add = hash(table[i]->key);
            while(newTable[add] != NULL){
                add += hash2(table[i]->key);
                add %= tableSize;
            }
            newTable[add] = table[i];
            cout << "Key(" << table[i]->key << ") rentered at address(" <<add <<")" << endl;
        }
    }
    table.resize(tableSize);
    table.assign(newTable.begin(), newTable.end());
}
void OAHT::set(KeyType key, ValueType value){
    
    //double the size if 50% if table is occupied.
    if(occupiedNum >= (tableSize / 2)){
        rehash();
    }
    
    int address = hash(key);
    while(table[address] != NULL){
        cout << "Collision Occured at address " << address << " key " << key << endl;
        address += hash2(key);
    }
    
    table[address] = new ONode(key, value, OCCUPIED);
    cout << "Key(" << key << ") entered at address(" <<address <<")" << endl;
    occupiedNum++;
}

ValueType OAHT::get(KeyType key){
    int address = hash(key);
    while(table[address]->key != key){
        address += hash2(key);
        address %= tableSize;
    }
    return table[address]->value;
}
