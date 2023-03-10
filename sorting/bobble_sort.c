#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void bobble_sort(int arr[], int size);
void print_array(int arr[], int size);

void print_array(int arr[], int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}

void bobble_sort(int arr[], int size)
{
    int i,j,temp,n=size;

    for(i=0;i<n-1;i++){
        for(j=1;j<n;j++){
            if(arr[j-1]>arr[j]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main()
{
    int arr[]={5,2,5,2,5,4,8,9,4,2,4,7,8,};
    int size=sizeof(arr)/sizeof(int);

    print_array(arr,size);
    bobble_sort(arr,size);
    print_array(arr,size);

    getch();
}