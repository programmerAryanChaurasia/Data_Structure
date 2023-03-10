#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int b;
    int *arr;    
};

int isEmpty(struct queue *);
int isFull(struct queue *q);
int first_val(struct queue *q);
int last_val(struct queue *q);
void enqueue(struct queue *q);
void dequeue(struct queue *q);



int isEmpty(struct queue *q)
{
    if(q->f==q->b){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q)
{
    if((q->b+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int first_val(struct queue *q)
{
    if(q->f==q->b){
        return 1;
    }
    else{
        return q->arr[(q->f+1)%q->size];
    }   
}
int last_val(struct queue *q)
{
    if(q->f==q->b){
        return -1;
    }
    else{
        return q->arr[q->b];
    }
}
void enqueue(struct queue *q)
{
    if((q->b+1)%q->size==q->f){
        printf("\nQueue is fuLL.");
    }
    else{
        q->b=(q->b+1)%q->size;
        printf("\nEnter Number for Enque operation : ");
        scanf("%d",&q->arr[q->b]);
    }
}
void dequeue(struct queue *q)
{
    int val;
    if(q->f==q->b){
        printf("\nQueue is empty hence Deque operation not perform.");
    }
    else{
        q->f=(q->f+1)%q->size;
        val=q->arr[q->f];
        printf("\nDeque Element is %d .",val);
    }
}
int main()
{
    struct queue q;
    q.size=10;
    q.f=q.b=0;
    q.arr=(int*)malloc(sizeof(int)*q.size);

    enqueue(&q);
    enqueue(&q);
    enqueue(&q);
/*
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
 */   
    printf("\nFirst val = %d",first_val(&q));
    printf("\nlast val = %d",last_val(&q));


    getch();
}