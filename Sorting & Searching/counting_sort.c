#include<stdio.h>
void countingSort(int arr[], int n);
int main() {
    int arr[] = {8,2,3,2,4,1,9,0,0,2,10,0,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}
// where count sort is apllicable: where domain is limited and repeatations are there
// How its diff. from other sort: others do compare, but count sort does mathematical logics