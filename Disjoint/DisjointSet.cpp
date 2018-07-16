#include "DisjointSet.hpp"
DisjointSet::DisjointSet(){
    parent = NULL;
}
DisjointSet::DisjointSet(Type d){
    data = d;
    parent = NULL;
    
}

void DisjointSet::unionSet(DisjointSet * set){
    set->parent = this;
}

DisjointSet* DisjointSet::findSet(){
    DisjointSet * cur = this;
    while(cur->parent != NULL)
        cur = cur->parent;
    return cur;
}

DisjointSet* DisjointSet::makeSet(Type newData){
    data = newData;
    parent = NULL;
    return this;
}
