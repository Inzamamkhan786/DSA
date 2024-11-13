#include<stdio.h>
#include<stdlib.h>

struct node{
struct node*left;
int data;
struct node*right;
};
struct node*insert(struct node*root,int item);
struct node*new_Node(int item);
void Inorder(struct node*root);

int main(){
struct node*root=NULL;
insert(root,25);
insert(root,20);
insert(root,36);
insert(root,10);
insert(root,22);
insert(root,30);
insert(root,40);
insert(root,5);
insert(root,12);
insert(root,28);
insert(root,38);
insert(root,48);

Inorder(root);

    return 0;
}

struct node*insert(struct node*root,int item){

if(root==NULL){
    return (new_Node(item));
}else if(item > root->data){
    root->right=insert(root->right,item);
}else if(item<root->data){
    root->left=insert(root->left,item);
}
return root;
}




struct node*new_Node(int item){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void Inorder(struct node*root){
if(root!=NULL){
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

}


