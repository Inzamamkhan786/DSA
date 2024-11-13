#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *left;
int data;
struct node*right;
};
struct node*createNode(int val);
void inOrder(struct node*root);

int main(){
 struct node*root;
 root=createNode(786); //A
 root->left=createNode(12); //B
 root->left->right=createNode(8);  //D
 root->right=createNode(73);   //C
 root->right->left=createNode(59); //E
 root->right->left->left=createNode(90);  //G
 root->right->right=createNode(34);  //F
 root->right->right->right=createNode(18); //I
 root->right->right->left=createNode(82); //I
inOrder(root);

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

void inOrder(struct node*root){

    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }

}