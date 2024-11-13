#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int item[MAX_SIZE],front=-1,rear=-1;
void Enqueue(int);
void Dequeue();
void display();
int isFull();


void Enqueue(int data){
if(isFull()){
    return;
}
if(front==-1 && rear==-1){
front=0;
rear=rear+1;
item[front]=data;
}

front=0;
item[rear]=data;
rear=rear+1;
}

int isFull(){
if(rear==MAX_SIZE){
    return 1;
}else{
    return 0;
}
}
void Dequeue(){
int yoyo;
yoyo=front;
front++;
free(item[yoyo]);

}


void display(){

    int yoyo;
    yoyo=front;
    while(yoyo!=MAX_SIZE){
        printf("%d ", item[yoyo]);
        yoyo++;
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
display();

    return 0;
}


