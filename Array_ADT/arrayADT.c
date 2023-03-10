#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};
//Function Declaration.
struct myArray * creat_array(int);
int getItem(struct myArray *, int);
int insert_at_end(struct myArray *,int);
int insert_at_index(struct myArray *,int, int);
int update_item(struct myArray *b ,int , int);
int count_item(struct myArray *);
int remove_item(struct myArray *, int index);
void display_All_item(struct myArray *);
int search_item(struct myArray *, int);
void sort_array(struct myArray *);

struct myArray * creat_array(int total_size)
{
    struct myArray *b;
    b=(struct myArray *)malloc(sizeof(struct myArray));
    b->total_size=total_size;
    b->used_size=-1;
    b->ptr=(int *)malloc(sizeof(int)*b->total_size);
    return b;
}
int getItem(struct myArray *b, int index)
{
    if((index<0)||(index>b->used_size)){
        return -1;
    }
    else{
        return(b->ptr[index]);
    }
}
int insert_at_end(struct myArray *b, int value)
{   
    if((b->used_size)<b->total_size){
        b->used_size=b->used_size+1;
        b->ptr[b->used_size]=value;
        return (b->used_size);
    }
    else{
        return(-1);
    }
}
int insert_at_index(struct myArray *b,int value, int index)
{
    int i;

    if(((b->total_size)-1)<=(b->used_size)){
        printf("\nArray is Full\nNo more space for insert more data!");
        return (-1);
    }
    if(index<0||(index>((b->used_size)+1))){
        printf("\nInvalid index!");
        return (-1);
    }
    for(i=b->used_size;i>=index;i--){
        b->ptr[i+1]=b->ptr[i];
    }
    b->used_size=b->used_size+1;//This line is most important.
    b->ptr[index]=value;
    printf("\nInsertion at index %d is Succcess full",index);
    return 1;
}
int update_item(struct myArray *b ,int value , int index)
{
   if(index<0||(index>((b->used_size)))){
        printf("\nInvalid index!");
        return (-1);
    }
    else{
        b->ptr[index]=value;
        return 1;
    }
}
int count_item(struct myArray *b){
    return b->used_size;
}
int remove_item(struct myArray *b, int index)
{
    int i;
    if(index<0||index>b->used_size){
        printf("\nPlease Enter valid index!");
        return(-1);
    }
    else{
        for(i=index;i<b->used_size;i++){
            b->ptr[i]=b->ptr[i+1];
        }
        b->used_size=b->used_size-1;
        return (1);
    }
}
void display_All_item(struct myArray *b)
{
    int i;
    if(b->used_size==-1){
        printf("\nArray is Fully Empty");
    }
    else{
        printf("\nDisplay All Element!\n");
        for(i=0;i<=b->used_size;i++){
            printf("%d\t",b->ptr[i]);
        }
    } 
}
int search_item(struct myArray *b, int value)
{
    int i;
    if(b->used_size==-1){
        printf("\nNot any element present in Array. Array is fully Empty.");
        return 0;
    }
    //If Number Present the return index number else return 0.
    else{
        for(i=0;i<=b->used_size;i++){
            if(b->ptr[i]==value){
                return i;
            }
        }
        printf("Number is not present in array!");
        return (-1);
    }
}
void sort_array(struct myArray *b)
{
    int i,j,temp;
    if(b->used_size==-1){
        printf("\nArray id Empty");
    }
    if(b->used_size==0){
        printf("\nIn array only one element present hence it is sorted!");
    }
    for(i=0;i<=b->used_size-1;i++){
        for(j=i+1;j<=b->used_size;j++){
            if(b->ptr[i]>b->ptr[j]){
                temp=b->ptr[i];
                b->ptr[i]=b->ptr[j];
                b->ptr[j]=temp;
            }
        }
    }

}

int main(){

    struct myArray *b;
    b=creat_array(10);
    int a=insert_at_end(b,12);
    a=insert_at_end(b,15);
   
    int d=insert_at_index(b,20,0);

    int e=update_item(b,30,1);
    if(e==1){
        printf("\nData Upadatin Process Is Success!");
    }
    else{
        printf("\nPlease Enter valid index!");
    }
    int c=getItem(b,1);
    if(c==-1){
        printf("\nData not inserted!");
    }
    else{
        printf("\nData Inserted data = %d",c);
    }
    int f=count_item(b);
    if(f==-1){
        printf("\nArray full Empty");
    }
    else{
        printf("\n%d Item present in Array",f+1);
    }
    display_All_item(b);
    sort_array(b);
    display_All_item(b);

    getch();
}