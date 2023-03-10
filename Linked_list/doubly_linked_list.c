#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *start=NULL;

struct node * creat_node();
void display();
void insert_at_beg();
void insert_at_last();
void insert_after();
void delete_first();
void delete_last();
void delete_after();

struct node * creat_node()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->prev=NULL;
    n->next=NULL;
    return n;
}
void display()
{
    struct node *t;

    if(start==NULL){
        printf("\nList is empty!");
        return ;
    }
    else{
        printf("\nDisplay all list of data : ");
        t=start;
        do{
            printf("%d\t",t->info);
            t=t->next;
        }while(t!=NULL);
    }
}
void insert_at_beg()
{
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter data to insert at begning of node : ");
    scanf("%d",&n->info);

    if(start==NULL){
        start=n;
    }
    else{
        n->next=start;
        start->prev=n;
        start=n;
    }
}
void insert_at_last()
{
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter data to insert at end od node : ");
    scanf("%d",&n->info);

    if(start==NULL){
        start=n;
    }
    else{
        t=start;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=n;
        n->prev=t;
    }
}
void insert_after()
{
    int val;
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter Element to Insert after node : ");
    scanf("%d",&n->info);

    printf("\nEnter data volue where After this data we insert %d volue.",n->info);
    scanf("%d",&val);

    if(start==NULL){
        printf("\nLinked is empty!");
        return ;
    }
    else{
        t=start;
        while(t->info!=val){
            t=t->next;
        }
        n->next=t->next;
        n->prev=t;
        t->next->prev=n;
        t->next=n;
    }
}
void delete_first()
{
    struct node *t;
    
    if(start==NULL){
        printf("\nList is fully Emptu!.");
    }
    else{
        printf("\n\nDelet the first node of list!");
        t=start;
        start=start->next;
        start->prev=NULL;
        free(t);
    }

}
void delete_last()
{
    struct node *t,*p;
    if(start==NULL){
        printf("\n\nList is empty!");
    }
    else{
        t=start;
        p=t;
        while(t->next!=NULL){
            p=t;
            t=t->next;
        }
        p->next=NULL;
        free(t);
    }
}
void delete_after()
{
    int val;
    struct node *t,*p;

    printf("\nEnter volue to delete after node : ");
    scanf("%d",&val);

    if(start==NULL){
        printf("List is fully empty");
        return ;
    }
    else{
        t=start;
        while(t->info!=val){
            t=t->next;
        }
        if(t->next->next==NULL){  //If delete hone vala node last node h.
            p=t->next;
            t->next=NULL;
            free(p);
        }
        else{
             p=t->next;
            t->next=p->next;
            p->next->prev=t;
            free(p);
        }
    }
}
int main()
{
    insert_at_beg();
    insert_at_beg();
    display();

    insert_at_last();
    insert_at_last();
    insert_at_last();
    insert_at_last();
    insert_at_last();
    insert_at_last();
    display();
/*
    insert_after();
    display();

    delete_first();
    display();
    
    delete_last();
    display();
*/
    delete_after();
    display();
    
    getch();
}