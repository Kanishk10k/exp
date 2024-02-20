#include<stdio.h>

int search(int arr[], int size, int n){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==n)
            return i;
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n;
    printf("Enter any element to be searched: ");
    scanf("%d",&n);
    int size=sizeof(arr)/sizeof(int);
    int ans=search(arr,size,n);
    if(ans==-1)
        printf("Element not found\n");

    else
        printf("Element %d is found at index %d\n",n,ans);

    return 0;
}