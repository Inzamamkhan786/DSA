#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node* link;
};
struct node* insert_at_desired(struct node* head,int value,int pos);
void print(struct node* head);

int main(){
    struct node* head;
    time_t t;
time(&t);
printf("Current date and time is :%s", ctime(&t));
printf("BT23CSH053 (Mohd Inzamamul Haque)\n");
    struct node* insert_at_desired(struct node* head,int value,int pos);
    int value,pos;
    printf("Enter the value\n");
    scanf("%d", &value);
    printf("Enter the position where you want to insert\n");
    scanf("%d", &pos);
    //function call for inserting the node at desired place;
    head=insert_at_desired(head,value,pos);
    print(head);

    return 0;
}

struct node* insert_at_desired(struct node* head,int value,int pos){
struct node *current1,*current2,*current3,*current4,*ptr,*newNode;
current1=(struct node*)malloc(sizeof(struct node));
current2=(struct node*)malloc(sizeof(struct node));
current3=(struct node*)malloc(sizeof(struct node));
current4=(struct node*)malloc(sizeof(struct node));
newNode=(struct node*)malloc(sizeof(struct node));
int i;
head=current1;
head->link=current2;
head->link->link=current3;
head->link->link->link=current4;
head->link->link->link->link=NULL;
head->data=23;
head->link->data=51;
head->link->link->data=39;
head->link->link->link->data=99;
newNode->data=value;
ptr=head;

for(i=0; i<pos-2 && ptr!=NULL; i++){

    ptr=ptr->link;
}
newNode->link=ptr->link;
ptr->link=newNode;
return head;
}
void print(struct node* head){
int i;
struct node* str;
str=head;
while(str!=NULL){
    printf("%d ", str->data);
    str=str->link;
}
return;
}

