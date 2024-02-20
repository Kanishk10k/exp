#include<stdio.h>

void merge(int a[],int l,int h, int m){
    int n1=m+1,n2=h-m;
    int p[n1],q[n2];
    for(int i=0;i<=m;i++)
        p[i]=a[i];

    for(int i=m+1;i<h;i++)
        q[i-m-1]=a[i];

    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(p[i]<q[j]){
            a[k]=p[i];
            i++,k++;
        }

        else{
            a[k]=q[j];
            k++,j++;
        }
    }

    while(i<n1){
        a[k]=p[i];
        i++,k++;
    }

    while(j<n1){
        a[k]=q[j];
        j++,k++;
    }

    for(i=0;i<=h;i++)
        printf("%d\t",a[i]);
}

int main(){
    int arr[]={5,6,12,14,4,8,13,15} , n=8;
    int h=n-1,l=0;
    int m=(h+l)/2;
    merge(arr,l,h,m);
    return 0;
}