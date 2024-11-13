#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node* link;
};

struct node *head;
struct node* bubble_sort(struct node*head);

int main(){
time_t t;
 time(&t);
 printf("Current date and time is :%s", ctime(&t));
 printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
 head=bubble_sort(head);
return 0;
}

struct node* bubble_sort(struct node*head){
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
head->link->data=69;
head->link->link->data=51;
head->link->link->link->data=11;
current4->link=NULL;
ptr=head;
while(ptr->link!=NULL){
    if(ptr->data>ptr->link->data){
        int temp;
        temp=ptr->data;
        ptr->data=ptr->link->data;
        ptr->link->data=temp;
    }
    ptr=ptr->link;
}
 while(ptr!=NULL){
    printf("%d", ptr->data);
    ptr=ptr->link;
 }
return head;
}

