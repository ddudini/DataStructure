#include "dataType.hpp"

void testDLL(){
    DLL dll = DLL();
    dll.add(1);
    dll.add(10);
    dll.add(8);
    dll.add(5);
    dll.add(3);
    dll.add(2);
    dll.add(9);
    dll.add(-1);
    dll.add(4);
    dll.add(6);
    
    dll.PrintList();
    
}
void testSort(){
    
    int arr[7] = {10,9,8,7,6, 13, -1};
    for(int i=0; i < 7 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Bubble Sort:       ";
    BubbleSort(arr, 7);
    
    for(int i=0; i < 7 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    cout << "Insertion Sort:        ";
    int arr2[7] = {10,9,8,7,6, 13, -1};
    
    InsertionSort(arr2, 7);
    
    for(int i=0; i < 7 ; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "Quick Sort:        ";
    int arr3[7] = {10,9,8,7,6, 13, -1};
    
    QuickSort(arr3, 0, 6);
    
    for(int i=0; i < 7 ; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
}

void testRBT(){
    /*
    RBT rbt = RBT();
    rbt.insertNode(10);
    rbt.preOrder(rbt.root); cout << endl;
    
    rbt.insertNode(5);
    rbt.insertNode(3);
    rbt.insertNode(4);
    rbt.insertNode(7);
    rbt.preOrder(rbt.root); cout << endl;
    
    rbt.insertNode(11);
    rbt.insertNode(12);
    rbt.insertNode(13);
    rbt.preOrder(rbt.root); cout << endl;
     */
    RBT rbt = RBT();
    rbt.insertNode(10);
    rbt.insertNode(7);
    rbt.insertNode(11);
    rbt.rotateRight(rbt.root);
    rbt.preOrder(rbt.root);
    rbt.rotateLeft(rbt.root);
    rbt.rotateLeft(rbt.root);
    rbt.preOrder(rbt.root);

}

void testHeap(){
    Heap heap = Heap(10);
    for(int i=0 ; i < 10; i++){
        int r = rand() % 10;
        heap.insert(r);
        heap.printNode();
    }
    heap.insert(11);
    heap.printNode();
    heap.deleteMin();
    heap.printNode();
    heap.deleteMin();
    heap.printNode();
    
}

void testPQ(){
    PQ pq = PQ(10);
    for(int i=0 ; i < 10; i++){
        int r = rand() % 10;
        int rd = rand() % 100;
        pq.PQ_enqueue(r, (void*) rd);
    }
    pq.printNode();
}

void testCHT(){
    CHT ht = CHT(12289);
    ht.set("MSFT","Microsoft Corporation");
    ht.set("JAVA", "Sun Microsystem");
    ht.set("REDH",   "Red Hat Linux");
    ht.set("APAC",   "Apache Org");
    ht.set("ZYMZZ",  "Unisys Ops Check");
    ht.set("IBM",    "IBM Ltd.");
    ht.set("ORCL",   "Oracle Corporation");
    ht.set("CSCO",   "Cisco Systems, Inc.");
    ht.set("GOOG",   "Google Inc.");
    ht.set("YHOO",   "Yahoo! Inc.");
    ht.set("NOVL",   "Novell, Inc.");
    
    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT",   ht.get( "MSFT" ).c_str() );
    printf("Key:%s, Value:%s\n", "REDH",   ht.get( "REDH" ).c_str() );
    printf("Key:%s, Value:%s\n", "APAC",   ht.get( "APAC" ).c_str() );
    printf("Key:%s, Value:%s\n", "ZYMZZ",  ht.get( "ZYMZZ" ).c_str() );
    printf("Key:%s, Value:%s\n", "JAVA",   ht.get( "JAVA" ).c_str() );
    printf("Key:%s, Value:%s\n", "IBM",    ht.get( "IBM" ).c_str() );
    printf("Key:%s, Value:%s\n", "ORCL",   ht.get( "ORCL" ).c_str() );
    printf("Key:%s, Value:%s\n", "CSCO",   ht.get( "CSCO" ).c_str() );
    printf("Key:%s, Value:%s\n", "GOOG",   ht.get( "GOOG" ).c_str() );
    printf("Key:%s, Value:%s\n", "YHOO",   ht.get( "YHOO" ).c_str() );
    printf("Key:%s, Value:%s\n", "NOVL",   ht.get( "NOVL" ).c_str() );
}

void testOAHT(){
    OAHT ht = OAHT(11);
    
    ht.set("MSFT","Microsoft Corporation");
    ht.set("JAVA", "Sun Microsystem");
    ht.set("REDH",   "Red Hat Linux");
    ht.set("APAC",   "Apache Org");
    ht.set("ZYMZZ",  "Unisys Ops Check");
    ht.set("IBM",    "IBM Ltd.");
    ht.set("ORCL",   "Oracle Corporation");
    ht.set("CSCO",   "Cisco Systems, Inc.");
    ht.set("GOOG",   "Google Inc.");
    ht.set("YHOO",   "Yahoo! Inc.");
    ht.set("NOVL",   "Novell, Inc.");
    
    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT",   ht.get( "MSFT" ).c_str() );
    printf("Key:%s, Value:%s\n", "REDH",   ht.get( "REDH" ).c_str() );
    printf("Key:%s, Value:%s\n", "APAC",   ht.get( "APAC" ).c_str() );
    printf("Key:%s, Value:%s\n", "ZYMZZ",  ht.get( "ZYMZZ" ).c_str() );
    printf("Key:%s, Value:%s\n", "JAVA",   ht.get( "JAVA" ).c_str() );
    printf("Key:%s, Value:%s\n", "IBM",    ht.get( "IBM" ).c_str() );
    printf("Key:%s, Value:%s\n", "ORCL",   ht.get( "ORCL" ).c_str() );
    printf("Key:%s, Value:%s\n", "CSCO",   ht.get( "CSCO" ).c_str() );
    printf("Key:%s, Value:%s\n", "GOOG",   ht.get( "GOOG" ).c_str() );
    printf("Key:%s, Value:%s\n", "YHOO",   ht.get( "YHOO" ).c_str() );
    printf("Key:%s, Value:%s\n", "NOVL",   ht.get( "NOVL" ).c_str() );
}

void testGraph(){
    Graph G;
    
    /*  정점 생성 */
    Vertex* V1 = new Vertex( 1 );
    Vertex* V2 = new Vertex( 2 );
    Vertex* V3 = new Vertex( 3 );
    Vertex* V4 = new Vertex( 4 );
    Vertex* V5 = new Vertex( 5 );
    
    /*  그래프에 정점을 추가 */
    G.AddVertex( V1 );
    G.AddVertex( V2 );
    G.AddVertex( V3 );
    G.AddVertex( V4 );
    G.AddVertex( V5 );
    
    /*  정점과 정점을 간선으로 잇기 */
    G.AddEdge(new Edge(V1, V2, 0) );
    G.AddEdge(new Edge(V1, V3, 0) );
    G.AddEdge(new Edge(V1, V4, 0) );
    G.AddEdge(new Edge(V1, V5, 0) );
    
    G.AddEdge(new Edge(V2, V1, 0) );
    G.AddEdge(new Edge(V2, V3, 0) );
    G.AddEdge(new Edge(V2, V5, 0) );
    
    G.AddEdge(new Edge(V3, V1, 0) );
    G.AddEdge(new Edge(V3, V2, 0) );
    
    G.AddEdge(new Edge(V4, V1, 0) );
    G.AddEdge(new Edge(V4, V5, 0) );
    
    G.AddEdge(new Edge(V5, V1, 0) );
    G.AddEdge(new Edge(V5, V2, 0) );
    G.AddEdge(new Edge(V5, V4, 0) );
    
    G.printGraph();
    
    
    //배열 그래프
    Graph2 G2 = Graph2(5);
    G2.AddVertex(1);
    G2.AddVertex(2);
    G2.AddVertex(3);
    G2.AddVertex(4);
    G2.AddVertex(5);
    
    G2.AddEdge(1, 2, 0);
    G2.AddEdge(1, 3, 0);
    G2.AddEdge(1, 4, 0);
    G2.AddEdge(1, 5, 0);
    
    G2.AddEdge(2, 1, 0);
    G2.AddEdge(2, 3, 0);
    G2.AddEdge(2, 5, 0);
    
    G2.AddEdge(3, 1, 0);
    G2.AddEdge(3, 2, 0);
    
    G2.AddEdge(4, 1, 0);
    G2.AddEdge(4, 5, 0);
    
    G2.AddEdge(5, 1, 0);
    G2.AddEdge(5, 2, 0);
    G2.AddEdge(5, 4, 0);
    
    G2.printGraph2();

}
