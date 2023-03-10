//Check isBST
//Inserting a node in BST.
//Deleting a node in BST.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * creat_node(int value);
void inOrder(struct node *root);
void insert(struct node * root, int key);
int isBST(struct node * root, struct node *min, struct node *max);
struct node *delete_node(struct node *root, int value);
struct node* inOrderPredecessor(struct node * root);

struct node * creat_node(int value)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=value;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void inOrder(struct node *root)
{
    if(root!=NULL){
        inOrder(root->left);
        printf("\t%d",root->data);
        inOrder(root->right);
    }
}
void insert(struct node * root, int key)
{
    struct node *prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("Can NOT inserted %d because %d  ALL ready avalible in tree",key,key);
            return ;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node *new =creat_node(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }
 
}

int isBST(struct node * root, struct node *min, struct node *max)
{
    int leftSubtree;
    int rightSubtree;
    if(root==NULL){
        return 1;
    }
    if(min!=NULL && root->data<=min->data){
        return 0;
    }
    if(max!=NULL&&root->data>=max->data){
        return 0;
    }
    leftSubtree=isBST(root->left,min,root);
    rightSubtree=isBST(root->right,root,max);


    return(leftSubtree && rightSubtree);
}
//IN Order predecessor.
struct node* inOrderPredecessor(struct node * root)
{
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
//Struct Node Delete BST
struct node *delete_node(struct node *root, int value)
{
    struct node *ipre;

    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left=delete_node(root->left,value);
    }
    else if(value>root->data){
        root->right=delete_node(root->right,value);
    }
    else{
        ipre=inOrderPredecessor(root);
        root->data=ipre->data;
        root->left=delete_node(root->left,ipre->data);
    }
}
int main()
{
    int k;
    struct node *n;
    struct node *p =creat_node(5);
    struct node *p1 =creat_node(3);
    struct node *p2 =creat_node(7);
    struct node *p3 =creat_node(2);
    struct node *p4 =creat_node(4);

    //           5
    //          / \
    //         3   7
    //        / \
    //       2   4

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

/*
//check BST
    if(isBST(p,NULL,NULL)){
        printf("\nIt is legal BST");
    }
    else{
        printf("\nIt is not BST.");
    }
//    Insert Element in BST
    inOrder(p);
    insert(p,1);
    insert(p,8);
    insert(p,9);
    insert(p,6);
    printf("\n");
    inOrder(p);
*/

    inOrder(p);
    printf("\n");
    n = delete_node(p,5);
    inOrder(p);

    getch();
}