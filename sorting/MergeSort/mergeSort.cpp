#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Length of the left sub-array
    int n2 = right - mid;    // Length of the right sub-array

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Initial indexes for L[], R[], and merged subarray arr[]
    int i = 0, j = 0, k = left;

    // Merge the temp vectors back into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Left is for the left index and right is the right index of the sub-array of arr to be sorted
void merge_Sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = (left + (right - left)) / 2;

        // Sort the first and second halves
        merge_Sort(arr, left, mid);
        merge_Sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements in the array:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Call the merge sort function
    merge_Sort(arr, 0, n - 1);

    // Display the sorted array
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
