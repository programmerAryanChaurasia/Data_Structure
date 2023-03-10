//Quick sort follow divide and concour method.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void print_array(int arr[], int size);
int partions(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);

void print_array(int arr[], int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}
int partions(int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    if(low<high){ 
        int k=partions(arr,low,high);
        quick_sort( arr, low, k-1);
        quick_sort( arr, k+1, high);
    }

}

int main()
{
    int arr[]={5,2,5,2,5,4,8,9,4,2,4,7,8,};
    int size=sizeof(arr)/sizeof(int);

    print_array(arr,size);
    quick_sort( arr,  0, size-1);
    print_array(arr,size);

    getch();
}