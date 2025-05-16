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
    int sizes[] = {1000, 10000, 50000, 100000}; // Predefined input sizes
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int arr[n];

        // Generate random values for the array
        printf("Generating array of size %d...\n", n);
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000;  // Random values between 0 and 9999
        }

        merge_call_count = 0;
        mergesort_call_count = 0;

        // Measure the time taken to sort
        clock_t start_time = clock();  // Start measuring time
        mergesort(arr, 0, n - 1);      // Call merge sort
        clock_t end_time = clock();    // End measuring time

        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;  // Calculate time in seconds

        // Output results
        printf("Input Size: %d, Time Taken: %f seconds, Mergesort Calls: %d, Merge Calls: %d\n", 
               n, time_taken, mergesort_call_count, merge_call_count);
    }

    return 0;
}
