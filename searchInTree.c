#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *left;
int data;
struct node*right;
};
struct node*createNode(int val);
void search(struct node*root,int item);

int main(){
 struct node*root;
 root=createNode(25);
 root->left=createNode(20);
 root->left->right=createNode(22);
 root->left->left=createNode(10);
 root->left->left->left=createNode(5);
 root->left->left->right=createNode(12);
 root->right=createNode(36);
 root->right->right=createNode(40);
 root->right->left=createNode(30);
root->right->left->left=createNode(28);
 root->right->right->right=createNode(48);
printf("Enter the number you want to search in the tree\n");
int item;
scanf("%d", &item);

search(root,item);


    return 0;
}



struct node* createNode(int val){
struct node*newNode;
newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=val;
newNode->right=NULL;
newNode->left=NULL;
return newNode;
}

// void inOrder(struct node*root){

//     if(root!=NULL){
//         inOrder(root->left);
//         printf("%d ", root->data);
//         inOrder(root->right);
//     }

// }

void search(struct node*root,int item){
if(root==NULL){
    printf("%d is not present in the tree\n", item);
    return ;
}
if(root->data==item){
    printf("%d is present in the tree\n", item);
    return;
}

if(item>root->data){
    search(root->right,item);
}

if(item<root->data){
    search(root->left,item);
}


}