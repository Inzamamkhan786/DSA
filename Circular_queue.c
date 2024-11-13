#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int item[MAX_SIZE],front=-1,rear=-1;
void Enqueue(int);
void Dequeue();
void display();
int isFull();
int isEmpty();

void Enqueue(int data){
if(isFull()){
    return;
}
if(front==-1 && rear==-1){
front=0;
rear=rear+1;
item[front]=data;
}

rear=(rear+1)%MAX_SIZE;
item[rear]=data;
}

int isFull(){
if(front==rear+1||rear==MAX_SIZE){
    return 1;
}else{
    return 0;
}
}

void Dequeue(){
int yoyo;
if(isEmpty()){
printf("The queue is in underflow condition\n");
return;
}else{
 yoyo=front;
front++;
free(item[yoyo]);

}

}




void display(){
int i;
for(i=front; i!=rear; i=(i+1)%MAX_SIZE){
    printf("%d ", item[i]);    
}
}




int main(){

Enqueue(1);
Enqueue(2);
Enqueue(3);
Enqueue(4);
Enqueue(5);
display();
printf("\n");
printf("\n");
Dequeue();
Dequeue();
display();
printf("\n");
Enqueue(7);
Enqueue(8);
display();

    return 0;
}

int isEmpty(){
if(front==-1){
    return 1;
}else{
    return 0;
}

}

