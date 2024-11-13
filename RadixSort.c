#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int m);
int getMax(int arr[], int m);
int digit(int max);
void radixSort(int arr[], int m);
void count(int arr[], int m, int exp);
//int output[5];

int main(){
    int m,max,maxDigit;
    printf("Enter the size of the array: ");
    scanf("%d", &m);
    int arr[m],i,j;
    for(i=0; i<m; i++){
        scanf("%d", &arr[i]);
    }
    //displaying the user entered array;

    display(arr,m);
   // max=getMax(arr,m);
    //maxDigit=digit(max);
    //so with the help of function maxDigit we get the number of passes;

 
     radixSort(arr,m);
     printf("\n");
     printf("After sorting : ");

    display(arr,m);
   

    return 0;
}




void display(int arr[],int m){
for(int i=0; i<m; i++){
    printf("%d ", arr[i]);
}
}




int getMax(int arr[], int m){
int max=arr[0];
for(int i=0; i<m; i++){
    if(arr[i]>max){
        max=arr[i];
    }
}
return max;
}






int digit(int max){
    int count=0;
    while(max>0){
        max=max/10;
        count++;
    }
return count;
}

void count(int arr[], int m, int exp){
    int count[10]={0};
    int output[m];
    for(int i=0; i<m; i++){
        count[(arr[i]/exp)%10]++ ;
    }

    for(int i=1; i<10; i++){
        count[i]=count[i]+count[i-1];
    }
    
    for(int i=m-1; i>=0; i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
       // count[(arr[i]/exp)%10]--;
    }

    for(int i=0; i<m; i++){
        arr[i]=output[i];
    }


}







void radixSort(int arr[],int m){
int max = getMax(arr,m);
int exp=1;
while(max/exp>0){
    count(arr,m,exp);
    exp=exp*10;
}

}