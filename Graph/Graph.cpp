
#include "Graph.hpp"
Vertex::Vertex(){
    Next = NULL;
    AdjacencyList = NULL;
}
Vertex::Vertex(ElementType data){
    Vertex::data = data;
    v = NotVisited;
    index = -1;
    Next = NULL;
    AdjacencyList = NULL;
}
Edge::Edge(){
    fromV = NULL;
    toV = NULL;
    next = NULL;
}

Edge::Edge(Vertex *V1, Vertex *V2, int weight){
    Edge::weight = weight;
    fromV = V1;
    toV = V2;
    next = NULL;
}
Graph::Graph(){
    vertexCount = 0;
    vertices = NULL;
}
void Graph::AddVertex(Vertex *V){
    if(vertices == NULL){
        vertices = V;
    }
    else{
        Vertex * curV = vertices;
        while(curV->Next != NULL)
            curV = curV->Next;
        curV->Next = V;
    }
    vertexCount++;
}

void Graph::AddEdge(Edge *E){
    Vertex * from = E->fromV;
    Vertex * curV = vertices;
    
    while(curV != from)
        curV = curV->Next;
    
    if(curV->AdjacencyList == NULL){
        curV->AdjacencyList = E;
        return;
    }
    
    Edge * curE = curV->AdjacencyList;
    while(curE->next != NULL)
        curE = curE->next;
    curE->next = E;
}

void Graph::printGraph(){
    Vertex * cur = vertices;
    
    while (cur != NULL){
        printf("%d: ", cur->data);
        Edge * list = cur->AdjacencyList;
        while(list != NULL){
            printf("[%d->%d (%d)] ", list->fromV->data, list->toV->data, list->weight);
            list = list->next;
        }
        printf("\n");
        cur = cur->Next;
    }
}


Graph2::Graph2(int VertexNum){
    count = 0;
    Graph2::VertexNum = VertexNum;
    Vertices.resize(VertexNum);
    vector <int> temp = vector<int>(VertexNum, -1);
    Edges.resize(VertexNum, temp);
}
void Graph2::AddVertex(ElementType data){
    Vertices[count] = data;
    count++;
}
void Graph2::AddEdge(int fromV, int toV, int weight){
    Edges[fromV-1][toV-1] = weight;
}
void Graph2::printGraph2(){
    for(int i=0; i < VertexNum ; i++){
        printf("%d: ", Vertices[i]);
        for(int j=0; j < VertexNum ; j++){
            if(Edges[i][j] != -1)
               printf("[%d->%d (%d)] ", Vertices[i], Vertices[j], Edges[i][j]);
        }
        printf("\n");
    }
}
