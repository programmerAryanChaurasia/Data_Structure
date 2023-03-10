#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *n);
int isFull(struct stack *n);
int push(struct stack *n);
int pop(struct stack *n);
int stack_top(struct stack *n);
int stack_bottom(struct stack *n);
void display_all_data(struct stack *n);
void peek(struct stack *n);


int isEmpty(struct stack *n)
{
    if(n->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *n)
{
    if(n->top==n->size){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack *n)
{
    int val;
    int full_check=isFull(n);
    if(full_check){
        printf("\nStack overflow!");
        return 0;
    }
    else{
        printf("\nEnter Number : ");
        scanf("%d",&val);

        n->top++;
        n->arr[n->top]=val;  
        return 1;      
    }
}
int pop(struct stack *n)
{
    int val;
    if(isEmpty(n)){
        printf("\nStack is empty hence pop operation not done!");
        return -1;
    }
    else{
        val=n->arr[n->top];
        n->top--;
        return val;
    }
}
int stack_top(struct stack *n)
{
    if(isEmpty(n)){
        printf("Stack is fully Empty!");
        return -1;
    }
    else{
        return n->arr[n->top];
    }
}
int stack_bottom(struct stack *n)
{
    if(isEmpty(n)){
        printf("Stack is fully Empty!");
        return -1;
    }
    else{
        return n->arr[0];
    }
}
void display_all_data(struct stack *n)
{
    int i;
    if(isEmpty(n)){
        printf("\nStack is fully Empty!");
    }
    else{
        printf("\nAll data of stack : ");
        for(i=n->top;i>=0;i--){
            printf("%d\t",n->arr[i]);
        }
    }
    
}
void peek(struct stack *n)
{
    int val,k;
    if(isEmpty(n)){
        printf("\nStack is fully empty. Hence peek operation NOT perform.");
    }
    else{
        printf("\nEnter Number for performimg Peek operation : ");
        scanf("%d",&val);

        if((n->top+2-val)<0){
            printf("\nPlease enter valid index!");
        }
        else{
            k=(n->top+2)-val;
            printf("Your Peek value is %d",k);
        }
    }
}
int main()
{
    int val;
    struct stack *n;
    n=(struct stack *)malloc(sizeof(struct stack));
    n->top=-1;
    
    printf("\nEnter size of stack (size means maximun upto index) : ");
    scanf("%d",&n->size);

    n->arr=(int *)malloc(sizeof(int)*n->size);
/*
//-----------------------------------------------------------
    if(isEmpty(n)){
        printf("\nStack is Empty!");
    }
    else{
        printf("\nStack is Not Empty!");
    }
//------------------------------------------------------------
    if(isFull(n)){
        printf("\nStack is Full!");
    }
    else{
        printf("\nStack is Not Full!");
    }
//------------------------------------------------------------
    if(push(n)){
        printf("\nData inserted in stack is Successfull!");
    }
    else{
        printf("\nData Not inserted. Stack over flow.");
    }
//-------------------------------------------------------------
    val=pop(n);
    if(val==-1){
        printf("\n");
    }
    else{
        printf("\nYour poped data is %d",val);
    }
//-------------------------------------------------------------
*/  display_all_data(n);
    int a=push(n);
    a=push(n);
    a=push(n);
    a=push(n);
    a=push(n);
    display_all_data(n);
    peek(n);



getch();
}