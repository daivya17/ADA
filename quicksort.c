#include <stdio.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low+1,j = high;
    while(i<=j){
        while (i<=high && arr[i]<pivot) i++;
        while (j>=low && arr[j]>pivot) j--;
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j],&arr[low]);
    return j;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int p = partition(arr,low,high);
        quicksort(arr,low,p - 1);
        quicksort(arr,p + 1,high);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf("Enter the element:");
        scanf("%d", &arr[i]);
    }
    quicksort(arr,0,n - 1);
    printf("\nSorted array:");
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
