//  링크드리스트를 이용한 그래프 구현

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
using namespace std;

typedef int ElementType;
enum Visit {Visited, NotVisited};
class Vertex;
class Edge;
class Graph;

class Vertex{
public:
    ElementType data;
    int index;
    enum Visit v;
    Vertex * Next;          //다음 index vertex 저장
    Edge * AdjacencyList;   //인접 간선 저장
    
    Vertex();
    Vertex(ElementType data);
};

class Edge{
public:
    int weight;
    Vertex * fromV;
    Vertex * toV;
    Edge * next;    //인접 간선 저장
    Edge();
    Edge(Vertex* V1, Vertex * V2, int weight);
};

class Graph{
public:
    Vertex * vertices; //vertex 배열
    int vertexCount;
    
    Graph();
    void AddVertex(Vertex * V);
    void AddEdge(Edge * E);
    void printGraph();
};

//배열을 이용한 그래프 구현
class Graph2{
public:
    vector <ElementType> Vertices;
    vector <vector <int> > Edges;
    int VertexNum;
    int count;
    Graph2(int VertexNum);
    void AddVertex(ElementType data);
    void AddEdge(int fromV, int toV, int weight);
    void printGraph2();
    
};

#endif /* Graph_hpp */
