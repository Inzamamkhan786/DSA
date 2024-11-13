#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node* link;
};
struct node *head;
struct node* count_nodes(struct node*head,int *count);
int main(){
 int count=0;
 time_t t;
 time(&t);
 printf("Current date and time is :%s", ctime(&t));
 printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
//function call for countiing the nodes;
 head = count_nodes(head,&count);
 printf("The number of nodes in the linked list is %d", count);
    return 0;
}

struct node* count_nodes(struct node*head,int *count){
struct node *current1,*current2,*current3,*current4,*ptr;
current1=(struct node*)malloc(sizeof(struct node));
current2=(struct node*)malloc(sizeof(struct node));
current3=(struct node*)malloc(sizeof(struct node));
current4=(struct node*)malloc(sizeof(struct node));
head=current1;
head->link=current2;
head->link->link=current3;
head->link->link->link=current4;
head->data=25;
head->link->data=51;
head->link->link->data=69;
head->link->link->link->data=11;
current4->link=NULL;
ptr=head;
while(ptr!=NULL){
    ptr=ptr->link;
    *count=*count+1;
}
return head;
}