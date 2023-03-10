#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isEmpty(struct queue *q);
int isFull(struct queue *q);
void display_all(struct queue *q);
int first_val(struct queue *q);
int last_val(struct queue *q);
void enque(struct queue *q);
int dequeue(struct queue *q);

int isEmpty(struct queue *q)
{
    if(q->f==q->b)
        return 1;
    return 0;
}
int isFull(struct queue *q)
{
    if(q->size-1==q->b)
        return 1;
    return 0;
}
void display_all(struct queue *q)
{
    int i;
    printf("All Element of Queue : ");
    for(i=q->f+1;i<=q->b;i++)
        printf("%d\t",q->arr[i]);
}
int first_val(struct queue *q)
{
    if(q->f==q->b){
        return -1;
    }
    else{ 
        return q->arr[q->f+1];
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
void enque(struct queue *q)
{
    if(q->size-1==q->b){
        printf("\nQueue is full hence Enque is not possible!");
    }
    else{
        q->b++;
        printf("\nEnter element for Enque : ");
        scanf("%d",&q->arr[q->b]);
    }
}
int dequeue(struct queue *q)
{
    int val;
    if(q->f==q->b){
        return -1;
    }
    else{
        q->f++;
        val=q->arr[q->f];
        return val;
    }
}

int main()
{
    int val;
    struct queue q;
    printf("\nEnter size of queue : ");
    scanf("%d",&q.size);
    q.f=q.b=-1;
    q.arr=(int *)malloc(sizeof(int)*q.size);
/*
---------------------------------------------------------------------------------
    if(isEmpty(&q)){
        printf("\nQueue is Empty!");
    }
    else{
        printf("\nQueue is NOT Empty.");
    }
//-------------------------------------------------------------------------------
    if(isFull(&q)){
        printf("\nQueue is Full.");
    }
    else{
        printf("\nQueue is NOT Full.");
    }
//------------------------------------------------------------------------------

    enque(&q);
    enque(&q);
    enque(&q);
    enque(&q);
    enque(&q);
    enque(&q);
    val=dequeue(&q);
    if(val==-1){
        printf("\nQueue is Empty hence dequeue operation not perform.");
    }
    else{
        printf("\nDequeue operaton perforn and dequeue value is %d .",val);
    }
    val=dequeue(&q);
    printf("\nDequeue operaton perforn and dequeue value is %d .",val);
    val=dequeue(&q);
    printf("\nDequeue operaton perforn and dequeue value is %d .",val);
    val=dequeue(&q);
    printf("\nDequeue operaton perforn and dequeue value is %d .",val);
    val=dequeue(&q);
    printf("\nDequeue operaton perforn and dequeue value is %d .",val);
    val=dequeue(&q);
    printf("\nDequeue operaton perforn and dequeue value is %d .",val);
    val=dequeue(&q);
    printf("\nDequeue operaton perforn and dequeue value is %d .",val);
//------------------------------------------------------------------------------------
*/
    getch();
}