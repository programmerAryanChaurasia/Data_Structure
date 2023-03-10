#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *last=NULL;

struct node * creat_node();
void display();
void Add_at_beg();
void add_at_end();
void add_after();
void delete_last();
void delete_first();

struct node * creat_node()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->next=n;
    return n;
}
void display()
{
    struct node *t;

    if(last==NULL){
        printf("\nNot any element present in list. List is fully empty!");
    }
    else{
        printf("\nAll data of list. : ");
         t=last->next;
        do{
            printf("%d\t",t->info);
            t=t->next;
        }while(t!=last->next);
    }
   
}
void Add_at_beg()
{
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter Data to insert at begnning : ");
    scanf("%d",&n->info);

    if(last==NULL){
        last=n;
        last->next=n;
    }
    else{
        n->next=last->next;
        last->next=n;
    }
}
void add_at_end()
{
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter number to Add node at end : ");
    scanf("%d",&n->info);

    if(last==NULL){
        last=n;
        n->next=last;
    }
    else{
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
void add_after()//Ham user se ek data input karayege and list me vah data jaha hoga usake baad insert karayege.
{
    int val;
    struct node *n,*t;
    n=creat_node();

    printf("\nEnter data to store in list in between : ");
    scanf("%d",&n->info);

    printf("Enter node data value where after we store %d value",n->info);
    scanf("%d",&val);

    if(last==NULL){
        printf("List is fully empty");
    }
    else{
        if(last->info==val){
            n->next=last->next;
            last->next=n;
            last=n;
        }
        else{
            t=last->next;
            while(t->info!=val){
                t=t->next;
            }
            n->next=t->next;
            t->next=n;
        }
    }

}
void delete_last()
{
    struct node *t,*p;
    if(last==NULL){
        printf("\nNode is fully empty!");
    }
    else{
        printf("\nAfter last node delection.");
        t=last->next;
        while(t->next!=last){
            t=t->next;
        }
        p=last;
        t->next=last->next;
        last=t;
        free(p);
    }
}
void delete_first()
{
    struct node *n,*t;
    if(last==NULL){
        printf("\n\nList is fully empty!");
    }
    else{
        printf("\n\nAfter first node delection!");
        t=last->next;
        last->next=t->next;
        free(t); 
    }
    
}


int main()
{
    Add_at_beg();
    Add_at_beg();
    Add_at_beg();
    display();
/*
    add_at_end();
    add_at_end();
    display();

    add_after();
    display();

    delete_last();
    display();
*/
    delete_first();
    display();

    getch();
}