#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node* link;
};

struct node* insert_at_end(struct node* head,int value);

int main(){
struct node* head;
time_t t;
time(&t);
printf("Current date and time is :%s", ctime(&t));
printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
int value;
printf("Enter the value\n");
scanf("%d", &value);

//function call for inderting the node at the END;
head=insert_at_end(head,value);

    return 0;
}

struct node* insert_at_end(struct node* head,int value){
struct node *current1,*current2,*current3,*newNode,*ptr,*str;
current1=(struct node*)malloc(sizeof(struct node));
current2=(struct node*)malloc(sizeof(struct node));
current3=(struct node*)malloc(sizeof(struct node));
newNode=(struct node*)malloc(sizeof(struct node));
head=current1;
head->data=12;
head->link=current2;
head->link->data=24;
head->link->link=current3;
head->link->link->data=45;
head->link->link->link=NULL;

newNode->data=value;
newNode->link=NULL;
str=head;

ptr=head;
while(ptr->link!=NULL){
    ptr=ptr->link;
}
ptr->link=newNode;
int i;
for(i=1; i<=4 && str!=NULL; i++){
 printf("%d ",str->data );
 str=str->link;
}


}