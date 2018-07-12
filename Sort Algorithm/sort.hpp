

#ifndef sort_hpp
#define sort_hpp

#include <iostream>
typedef int ElementType;
using namespace std;

void swap(ElementType * A, ElementType * B);
void BubbleSort(ElementType arr [], int length);
void InsertionSort(ElementType arr[], int length);
void QuickSort(ElementType arr[], int leftIndex, int rightIndex);
#endif /* sort_hpp */
