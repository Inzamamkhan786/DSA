#include<stdio.h>

void printHeap(int heap[], int n);
void deleteElement(int heap[], int *n);
void heapify(int heap[], int n, int i);
void swap(int *a, int *b);

int main(){
    int heap[] = {50,30,20,15,10,8,16};
    int n = sizeof(heap)/sizeof(heap[0]);
    
    printf("Original Heap: ");
    printHeap(heap,n);

    deleteElement(heap,&n);
    printf("After Deleting the root element\n");
    printHeap(heap,n);
    return 0;
}


void printHeap(int heap[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void deleteElement(int heap[], int *n){
    if((*n)<=0){
        printf("The heap is empty!!\n");
        return;
    }

    heap[0] = heap[*n - 1];
    (*n)--;

    heapify(heap,*n,0);

}

void heapify(int heap[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && heap[largest]<heap[left]){
        largest = left;
    }

    if(right<n && heap[largest]<heap[right]){
        largest = right;
    }

    if(largest!=i){
        swap(&heap[i],&heap[largest]);
        heapify(heap,n,largest);
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}