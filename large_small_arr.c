//find the second largest and second smallest element in an array

#include <stdio.h>
#include <limits.h> // Required for INT_MIN and INT_MAX

void findSecondLargestSmallest(int arr[], int n) {
    if (n < 2) {
        printf("Array size is too small to find second largest/smallest elements.\n");
        return;
    }

    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Logic for largest and second largest
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        // Logic for smallest and second smallest
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    // Handle cases where all elements are the same or only two elements exist
    if (secondLargest == INT_MIN || secondSmallest == INT_MAX) {
        printf("Could not find distinct second largest/smallest elements (e.g., all elements are identical).\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
        printf("The second smallest element is: %d\n", secondSmallest);
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSecondLargestSmallest(arr, n);

    return 0;
}
