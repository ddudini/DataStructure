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
