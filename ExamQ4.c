#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void insert(struct node**head,int data);
void display(struct node*head);
struct node*createNode(int d);
int maxDigit(struct node*head);
void radixSort(struct node**head);
struct node* counting(struct node**head,int exp);


int main(){
    struct node*head=NULL;


    insert(&head,55);
    insert(&head,98);
    insert(&head,12);
    insert(&head,543);
    insert(&head,5);
    insert(&head,21);
    insert(&head,67);
    insert(&head,29);

    printf("Before Sorting : ");
    display(head);

    radixSort(&head);

    printf("\nAfter sorting : ");
    display(head);

  return 0;
}


void insert(struct node**head, int d){
    struct node*newNode = createNode(d);
    if(newNode == NULL){
        printf("OverFlow\n");
        return;
    } 
    if((*head)==NULL){
    (*head)=newNode;
    return;
    }


    struct node* temp = (*head);
    while(temp->next!=NULL){
        temp = temp->next;
    }
     temp->next = newNode;
     temp = newNode;
    
return;
}



struct node*createNode(int d){
struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}


void display(struct node*head){
    struct node*temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

int maxDigit(struct node*head){
    struct node*ptr = head;
     int max = ptr->data;
     while(ptr!=NULL){
        if(ptr->data > max){
            max = ptr->data;
        }
        ptr = ptr->next;
     }   
     return max;
}


void radixSort(struct node**head){
    int max = maxDigit((*head));
    int exp = 1;
    while(max/exp > 0){
   *head = counting((head),exp);
    exp = exp*10;
    }
}


struct node*counting(struct node**head, int exp){
 struct node*output = NULL;
 struct node*bucket[10] = {NULL};
 struct node*temp = (*head);

while(temp!=NULL){
    int index = ((temp->data)/exp)%10;
    insert(&bucket[index],temp->data);
    temp = temp->next;
}

for(int i=0; i<10; i++){
    while(bucket[i]!=NULL){
        if(output==NULL){
            output = bucket[i];
        }else{
       struct node*temp =output;
       while(temp->next!=NULL){
        temp = temp->next;
       }
       temp->next = bucket[i];

        }
        

    }

}
  *head = output;


}

   