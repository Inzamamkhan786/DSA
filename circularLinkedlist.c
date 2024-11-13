#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node* createNode(int value);

int main(){
    struct node*head,*current1,*current2,*current3,*current4,*current5;
    int i,value;
    for(i=1; i<=5; i++){
        printf("Enter the data in the node %d", i);
        scanf("%d", value);
        currenti=createNode(value);
    }


    return 0;
}
struct node* createNode(int value){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    return temp;
}