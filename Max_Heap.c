#include<stdio.h>
#define MAX_SIZE 100
int heap[MAX_SIZE];
int heapSize = 0;

int parent(int i){
    return (i-1)/2;
}
int leftChild(int i){
    return (2*i+1);
}
int rightChild(int i){
    return (2*i + 2);
}

void swap(int *a,int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value){
    if(heapSize == MAX_SIZE){
        printf("Heap is full");
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    heap[i] = value;

    while(i!=0 && heap[parent(i)]<heap[i]){
        swap(&heap[i],&heap[parent(i)]);
        i = parent(i);
    }
}

void printHeap(){
    for(int i=0; i<heapSize; i++){
        printf("%d ", heap[i]);
    }
}

int main(){
    insert(14);
    insert(24);
    insert(12);
    insert(11);
    insert(25);
    insert(8);
    insert(35);
   
   printHeap();

return 0;

}