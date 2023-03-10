#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void selection_sort(int arr[], int size);
void print_array(int arr[], int size);

void print_array(int arr[], int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}

void selection_sort(int arr[], int size)
{
    int i,j,temp,n=size;

    for(i=0;i<n-1;i++){
        for(j=i;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
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
    selection_sort(arr,size);
    print_array(arr,size);

    getch();
}