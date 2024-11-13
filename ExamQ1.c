#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int m);
void radixSort(int arr[], int m);
int maxNo(int arr[],int m);
void count(int arr[], int m, int exp);
  void display(int arr[],int m);


int main(){
    int m,i;
    printf("Enter the size of an array: ");
    scanf("%d", &m);
    int arr[m];
    printf("Enter the elements in an array : \n");
    for(i=0; i<m; i++){
    scanf("%d", &arr[i]);
    }

    printf("Before radix sort: ");
    display(arr,m);

    radixSort(arr,m);

    //after sorting 
    printf("\nAfter soting : ");

    display(arr,m);
    return 0;

}



    int maxNo(int arr[],int m){
    int max = arr[0];

        for(int i=0; i<m; i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
    }



    void radixSort(int arr[], int m){
    int max = maxNo(arr,m);
    int exp = 1;
    while(max/exp > 0){
        count(arr,m,exp);
        exp = exp*10;
    }
    }



    void count(int arr[],int m,int exp){
    int count[10] = {0};
    int output[m];

    for(int i=0; i<m; i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1; i<10; i++){
        count[i] = count[i] + count[i-1];
    }

    for(int i=m-1; i>=0; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
    }

    for(int i=0; i<m; i++){
        arr[i] = output[i];
    }
    }



    void display(int arr[],int m){
        for(int i=0; i<m; i++){
            printf("%d ", arr[i]);
        }
    }