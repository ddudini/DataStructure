#include "sort.hpp"

void swap(ElementType * A, ElementType * B){
    ElementType temp = (*B);
    (*B) = (*A);
    (*A) = temp;
}

void BubbleSort(ElementType arr[], int length){
    for(int i=0 ; i < length-1; i++){
        for(int j=0 ; j < length-(i+1); j++) {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void InsertionSort(ElementType arr[], int length){
    for(int i=1 ; i < length; i++){
        if(arr[i-1] <= arr[i]) continue;
        
        int value = arr[i];
        
        for(int j=0 ; j < i ; j++){
            if(value < arr[j]){
                memmove(&arr[j+1], &arr[j], sizeof(arr[0]) * (i-j) );
                arr[j] = value;
                break;
            }
        }
    }
}

int Partition(ElementType arr[], int leftIndex, int rightIndex){
    int firstIndex = leftIndex;
    int Pivot = arr[firstIndex];
    leftIndex++;
    
    while(leftIndex <= rightIndex){
        while(arr[leftIndex] <= Pivot && leftIndex <= rightIndex)
            leftIndex++;
        while(arr[rightIndex] > Pivot && leftIndex <= rightIndex)
            rightIndex--;
       
        if(leftIndex < rightIndex)
            swap(arr[leftIndex], arr[rightIndex]);
        else break;
    }
    
    swap(arr[firstIndex], arr[rightIndex]);
    return rightIndex;
}

void QuickSort(ElementType arr[], int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int middle = Partition(arr, leftIndex, rightIndex);
        cout << middle << " " << arr[middle] << ": ";
        QuickSort(arr, leftIndex, middle-1);
        QuickSort(arr, middle+1, rightIndex);
        
        for(int i=0; i < 7 ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
