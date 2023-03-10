#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * creat_node(int value)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=value;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preOrder(struct node *root)
{
    if(root!=NULL){
        printf("%d\t",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if(root!=NULL){      
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t",root->data);
    }
}
void inOrder(struct node *root)
{
    if(root!=NULL){
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
}
int main()
{
    struct node *p =creat_node(4);
    struct node *p1 =creat_node(1);
    struct node *p2 =creat_node(6);
    struct node *p3 =creat_node(5);
    struct node *p4 =creat_node(2);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    printf("\nPreOrder Traversal : \n");
    preOrder(p);

    printf("\npostOrder Traversal : \n");
    postOrder(p);

    printf("\ninOrder Traversal : \n");
    inOrder(p);
}