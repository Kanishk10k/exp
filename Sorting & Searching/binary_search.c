#include <stdio.h>

int Search(int arr[], int l, int h, int n)
{
    if (h >= l) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == n)
            return mid;
        if (arr[mid] > n)
            return Search(arr, l, mid - 1, n);
        return Search(arr, mid + 1, h, n);
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(int);
    int n;
    printf("Enter the element to be searched: ");
    scanf("%d",&n);
    int result = Search(arr, 0, size - 1, n);
    (result == -1) ? printf("\nElement is not found\n") : printf("\nElement %d is present at index %d\n",n,result);
    return 0;
}