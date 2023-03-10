#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;

struct node* creat_node();
void insert_at_end();
void traverse();
void insert_at_beg();
void insert_at_specific_position();
void insert_after();
void delete_end();
void delete_first();


struct node * creat_node()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->next=NULL;
    return n;
}
void insert_at_end()
{
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter a number : ");
    scanf("%d",&n->info);

    n->next=NULL;

    if(start==NULL){
        start=n;
    }
    else{
        t=start;
        while (t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
    }
}
void insert_at_beg()
{
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter a number to add a begnning : ");
    scanf("%d",&n->info);

    n->next=NULL;

    if(start==NULL){
        start=n;
    }
    else{
        n->next=start;
        start=n;
    }
}
// Insert After k'th node.
void insert_at_specific_position()
{
    int k,count=0,not_valid=0;
    struct node *n,*t,*p;
    n=creat_node();

    printf("\nEnter a number to add at specific possition : ");
    scanf("%d",&n->info);
    n->next=NULL;

    printf("\nEnter node position Number : ");
    scanf("%d",&k);

    if((k==1)&&(start==NULL)){
        start=n;
    }
    if((start==NULL)&&(k>1)){
        printf("\nNot any element present in node. hence not insert node at %d position.",&k);
    }
    else{ 
        if(k==1){
            n->next=start;
            start=n;
        }
        else{
            t=start;
            p=t;
            count=0;
            while ((count)!=(k-1))
            {
                p=t;
                t=t->next;
                count++;
            }
            n->next=p->next;
            p->next=n;
        }
        
    }
}
//Insert After Data----(jis node me 100 data h usake baad insert kare.)
void insert_after()
{
    int k;
    struct node *n,*t;
    n=creat_node();

    if(start==NULL){
        printf("\nList is empty!");
        return ;
    }
    printf("\nEnter number to insrt after any data : ");
    scanf("%d",&n->info);
    n->next=NULL;

    printf("\nEnter Node data value where after you want to insert %d value : ",n->info);
    scanf("%d",&k);

    if(start->info==k){
        n->next=start->next;
        start->next=n;
    }
    else{
        t=start;
        while(t->info!=k){
            t=t->next;
        }
        n->next=t->next;
        t->next=n;
    }

}

//Delection of node.
void delete_end()
{

    struct node *t,*b;

    if(start==NULL){
        printf("\nNot any node in list!");
    }
    else{
        printf("\nAfter Delection of last node new data list!");
        t=start;
        b=t;
        while(t->next!=NULL){
            b=t;
            t=t->next;
        }
        b->next=NULL;
        free(t);
    }

}
void delete_first()
{
    struct node *t;

    if(start==NULL){
        printf("\nNOT any node avalible in list!");
    }
    else{
        t=start;
        start=start->next;
        free(t);

    }

}

void traverse()
{
    struct node *t;
    if(start==NULL){
        printf("\nNOt any element in node!\nPlease first insert Data.");
    }
    else{
        t=start;
        printf("\nAll data of linked list!\n");
        do{
            printf("%d\t",t->info);
            t=t->next;
        }while (t!=NULL);
        
    }
}
int main()
{
    insert_at_end();
    insert_at_end();
    insert_at_end();
    insert_at_end();
    traverse();

    insert_at_beg();
    traverse();

    insert_at_specific_position();
    traverse();

    insert_after();
    traverse();

    delete_end();
    traverse();

    delete_first();
    traverse();

    getch();
}  