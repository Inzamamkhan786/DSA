#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element%d: ",i+1);
        scanf("%d",&a[i]);
    }
    int max_freq=0;
    int max=a[0];
    for(int i=0;i<n;i++){
        int freq=0;
        for(int j=i;j<n;j++){
            if(a[i]==a[j]){
                freq++;
            }
        }
        if(max_freq<freq){
            max_freq=freq;
            max=a[i];
        }
    }
    printf("Mode of array is %d & frequency=%d",max,max_freq);
    return 0;}
