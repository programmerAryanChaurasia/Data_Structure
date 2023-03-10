#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertion_sort(int arr[], int size);
void print_array(int arr[], int size);

void print_array(int arr[], int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}

void insertion_sort(int arr[], int size)
{
    int i,j,temp,n=size,key;

    for(i=1;i<n;i++){
        key=arr[i];

        for(j=i-1;j>=0&&key<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={5,2,5,2,5,4,8,9,4,2,4,7,8,6,7,4,6,8,1,0,0,8,4,6,9,3,5};
    int size=sizeof(arr)/sizeof(int);

    print_array(arr,size);
    insertion_sort(arr,size);
    print_array(arr,size);

    getch();
}