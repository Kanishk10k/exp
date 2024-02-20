#include<stdio.h>

int main()
{
    int arr[] = {5,2,3,2,4,1,9};
    int s = sizeof(arr)/sizeof(arr[0]);
    int sm,t;

    for(int i=0; i<s; i++){
        sm=i;
        for(int j=i+1; j<s; j++){
            if(arr[j] < arr[sm])
                sm=j;
        }

        if(sm!=i){ 
            t = arr[sm];
            arr[sm] = arr[i];
            arr[i] = t;
        }
    }

    for(int i=0; i<s; i++)
        printf("%d  ", arr[i]);

    return 0;
}