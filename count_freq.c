//count frequency of each element in an array

#include <stdio.h>

void countFrequency(int arr[], int n) {
    // Array to keep track of visited elements. 0 means not visited, 1 means visited.
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Element | Frequency\n");
    printf("--------|----------\n");

    for (int i = 0; i < n; i++) {
        // Skip this element if it has already been counted
        if (visited[i] == 1) {
            continue;
        }

        // Count frequency of the current element
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                // Mark the duplicate element as visited
                visited[j] = 1;
            }
        }
        printf("%7d | %d\n", arr[i], count);
    }
}

int main() {
    int arr[] = {1, 2, 8, 3, 2, 2, 2, 5, 1};
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, n);

    return 0;
}
