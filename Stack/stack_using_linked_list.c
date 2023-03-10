#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;

struct stack * creat_node();
int isEmpty();
int isFull();
void push();
void pop();
void display();
void bottom_stack();
void stack_top();
void peek();

struct stack * creat_node()
{
    struct stack *n;
    n=(struct stack *)malloc(sizeof(struct stack));
    n->next==NULL;
    return n;
}
int isEmpty()
{
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull()
{
    struct stack *n;
    n=creat_node();
    if(n==NULL){
        return 1;  //Stack full tab hota h jab aap ke pc ka memory full ho jaye. then NULL return karata h
    }
    else{
        return 0;
    }
}
void push()
{
    struct stack *n;
    n=creat_node();

    if(isFull()){
        printf("\nStack is full hence push operation not done.");
    }
    else{
        printf("\nEnter Number to push the data in list : ");
        scanf("%d",&n->data);

            n->next=top;
            top=n; 
    }
}
void display()
{
    struct stack *t;
    
    if(isEmpty()){
        printf("\nStack is fully empty. Hence Display operation not perform.");
    }
    else{
        t=top;
        printf("\nList of data is : ");
        do{
            printf("%d\t",t->data);
            t=t->next;
        }while(t!=NULL);
    }
}
void bottom_stack()
{
    struct stack *t;
    
    if(isEmpty()){
        printf("\nStack is fully empty. Hence Display operation not perform.");
    }
    else{
        t=top;
        do{
            t=t->next;
        }while(t->next!=NULL);
        printf("\nBottom value of stack is %d .",t->data);
    }
}
void stack_top()
{
    
    if(isEmpty()){
        printf("\nStack is fully empty. Hence Display operation not perform.");
    }
    else{
        printf("\nTop value of stack is %d .",top->data);
    }
}
void pop()
{
    int val;
    struct stack *t;
    if(isEmpty()){
        printf("\nStack is fully Empty.");
    }
    else{
        val=top->data;
        t=top;
        top=top->next;
        free(t);
        printf("\nYour poped value is %d .",val);
    }
}
void peek()
{
    int pos,i;
    struct stack *t;
    if(isEmpty()){
        printf("\nStack is fully Empty.");
    }
    printf("\nFor Peek operation Enter position number : ");
    scanf("%d",&pos);
    t=top;
    for(i=0;(i<pos-1 && t!=NULL);i++){
        t=t->next;
    }
    if(t!=NULL){
        printf("\nPeek data is : %d",t->data);
    }
}
int main()
{
    printf("\n%d",isEmpty());
    printf("\n%d",isFull());
    push();
    push();
    push();
    push();
    push();
    push();
    push();
    display();
    bottom_stack();
    stack_top();
    peek();


}