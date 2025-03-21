#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int merge_call_count = 0;
int mergesort_call_count = 0;

void merge(int arr[], int low, int mid, int high) {
    merge_call_count++;
    int left = low, right = mid + 1;
    int temp[100], i = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[i++] = arr[left++];
    }

    while (right <= high) {
        temp[i++] = arr[right++];
    }

    for (int j = low; j <= high; j++) {
        arr[j] = temp[j - low];
    }
}

void mergesort(int arr[], int low, int high) {
    mergesort_call_count++;
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();
    mergesort(arr, 0, n - 1);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken to sort user input: %f seconds\n", time_taken);
    printf("Number of mergesort function calls: %d\n", mergesort_call_count);
    printf("Number of merge function calls: %d\n", merge_call_count);


    return 0;
}
