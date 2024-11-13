#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
int data;
struct node* link;
};

struct node* insertAtBegin(struct node* head,int value);


int main(){
struct node* head;
time_t t;
time(&t);
printf("Current date and time is :%s", ctime(&t));
printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
int value;
printf("Enter the number in the value\n");
scanf("%d", &value);

//function call for inserting the node at the beginning;
head = insertAtBegin(head,value);

    return 0;
}

struct node* insertAtBegin(struct node* head,int value){
struct node *current1,*current2,*current3,*newNode,*ptr,*str;
current1=(struct node*)malloc(sizeof(struct node));
current2=(struct node*)malloc(sizeof(struct node));
current3=(struct node*)malloc(sizeof(struct node));
newNode=(struct node*)malloc(sizeof(struct node));
head=current1;
str=newNode;
str->link=NULL;
str->data=value;
head->data=23;
head->link=current2;
head->link->data=46;
head->link->link=current3;
head->link->link->data=19;
head->link->link->link=NULL;
//creating the new node for inserting at the beginning;
str->link=head;
head=newNode;

int i;
ptr=head;
for(i=1; i<=4 && ptr!=NULL; i++){
    printf("%d ", ptr->data);
    ptr=ptr->link;
}

return head;
}