#include<stdio.h>
int binarysearch(int arr[], int beg, int end, int value);
int main(){
    int n,arr[n],value;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    printf("Enter the elements of an array\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    binarysearch(arr,0,n-1,value);

    return 0;
}

int binarysearch(int arr[], int beg, int end, int value){
int mid;
if(end>=beg){
mid = (end + beg)/2;
if(arr[mid]<value){
    return binarysearch(arr,mid+1,end,value);
}else if(arr[mid]>value){
    return binarysearch(arr,mid-1,beg,value);
}else if(arr[mid]==value){
    return printf("The search element is %d", arr[mid]);
}
}else {
return printf("The search element is not present in an array");
}
return;
}