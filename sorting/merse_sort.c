
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void merse_sort(int arr[], int low, int high);
void print_array(int *arr, int size);
void merse(int arr[], int low, int mid, int high);

void print_array(int *arr, int size)
{
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}
void merse(int arr[], int low, int mid, int high)
{
    int i,j;
    int k=low;
    int new_arr[100];
    i=low;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(arr[i]<arr[j]){
            new_arr[k]=arr[i];
            i++;
            k++;
        }
        else{
            new_arr[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        new_arr[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        new_arr[k]=arr[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++){
        arr[i]=new_arr[i];
    }
}

void merse_sort(int arr[], int low, int high)
{
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merse_sort(arr,low,mid);
        merse_sort(arr,mid+1,high);
        merse(arr,low,mid,high);
    }
}
int main()
{
    int arr[]={5,2,5,2,5,4,8,9,4,2,4,7,8,};
    int size=sizeof(arr)/sizeof(int);

    print_array(arr,size);
    merse_sort(arr,0,size-1);
    print_array(arr,size);

    getch();
}