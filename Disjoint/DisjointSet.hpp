//
//  DisjointSet.hpp
//  분리 집합 구현
//  자식이 부모를 가리키는 형태

#ifndef DisjointSet_hpp
#define DisjointSet_hpp

#include <stdio.h>

typedef char Type;
class DisjointSet{
    Type data;
    DisjointSet * parent;       //속한 집합 가르킴
    DisjointSet();
    DisjointSet(Type d);
    void unionSet(DisjointSet * withSet);
    DisjointSet* findSet();
    DisjointSet* makeSet(Type newData);
};
#endif /* DisjointSet_hpp */
