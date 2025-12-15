//find the kth largest & smallest element 

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort (for ascending order)
int compare_integers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void find_kth_min_max(int arr[], int size, int k) {
    // Input validation for K
    if (k < 1 || k > size) {
        printf("Invalid value of K (must be between 1 and %d)\n", size);
        return;
    }

    // Sort the array in ascending order
    qsort(arr, size, sizeof(int), compare_integers);

    // The Kth smallest element is at index k-1
    int kth_smallest = arr[k - 1];
    // The Kth largest element is at index size-k
    int kth_largest = arr[size - k];

    printf("The %dth smallest element is: %d\n", k, kth_smallest);
    printf("The %dth largest element is: %d\n", k, kth_largest);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    find_kth_min_max(arr, size, k);

    return 0;
}
