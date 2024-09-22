// Binary Insertion Sort is a variation of Insertion Sort that uses binary search to find the proper location to insert the selected element. This reduces the number of comparisons but does not change the worst-case time complexity, which remains 
// O(n^2). The advantage comes from reducing the comparisons to 𝑂(log 𝑛) for each element insertion.

// Algorithm:
// Traverse the array from the second element to the end.
// Use binary search to find the correct position of the current element in the sorted part of the array.
// Shift the elements in the sorted part to make space for the current element.
// Insert the current element at its correct position.

#include <iostream>
using namespace std;

// Function to perform binary search to find the insertion point
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid]) {
            return mid + 1;
        } else if (item > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// Function to perform binary insertion sort
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        // Find the position where current element should be inserted
        int pos = binarySearch(arr, current, 0, i - 1);

        // Shift elements to the right to make space for the current element
        int j;
        for (j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    binaryInsertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


// Explanation:
// Binary Search Function (binarySearch): This function finds the position where the current element should be inserted in the sorted part of the array.
// Binary Insertion Sort Function (binaryInsertionSort):
// It iterates over the array and for each element, it finds the correct position using binary search.
// Then it shifts the elements in the sorted part of the array to make space for the current element and inserts it at the correct position.
// Time Complexity: The overall time complexity remains 
// 𝑂(𝑛2) because although binary search reduces the comparison time to 
// 𝑂(log⁡𝑛)
// shifting the elements still takes𝑂(𝑛)
// Example:
// Input: arr[] = {12, 11, 13, 5, 6}

// Execution:

// After the first pass: arr[] = {11, 12, 13, 5, 6}
// After the second pass: arr[] = {11, 12, 13, 5, 6}
// After the third pass: arr[] = {5, 11, 12, 13, 6}
// After the fourth pass: arr[] = {5, 6, 11, 12, 13}
// Output: Sorted array: {5, 6, 11, 12, 13}