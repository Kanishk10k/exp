#include<stdio.h>
int main(){

    int a[10]={9,2,8,3,6,2,3,10,7,5};
    int i,j,k,key;
    for(i=1;i<10;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            a[j]=key;
            j--;
        }
    }
    for(k=0;k<10;k++)
        printf("%d\t",a[k]);
    return 0;
}