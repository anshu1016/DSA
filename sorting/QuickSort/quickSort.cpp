#include<bits/stdc++.h>
using namespace std;


// TIME COMPLEXITY (Average Case): O(n log n) due to the divide and conquer strategy.
// TIME COMPLEXITY (Worst Case): O(n²) when the pivot element consistently leads to unbalanced partitioning.
// SPACE COMPLEXITY: O(log n) due to recursion stack in average case, O(n) in the worst case.






int doPartition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // Choose the pivot element (first element of the array)
    int i = low;  // Starting index
    int j = high;  // Ending index
    
    while(i < j) {  // Continue until i and j cross each other
        
        // Move i to the right until you find an element greater than the pivot
        while(arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        
        // Move j to the left until you find an element smaller than the pivot
        while(arr[j] >= pivot && j >= low + 1) {
            j--;
        }
        
        // If i is still less than j, swap the elements at i and j
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    // Finally, place the pivot element in its correct position (j index)
    swap(arr[j], arr[low]);
    
    return j;  // Return the index where the pivot element is placed
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {  // If there is more than one element in the current segment
        // Perform partitioning and get the index of the pivot
        int partitionIndex = doPartition(arr, low, high);
        
        // Recursively apply QuickSort to the left side of the pivot
        quickSort(arr, low, partitionIndex - 1);
        
        // Recursively apply QuickSort to the right side of the pivot
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int n, i;
    
    cout << "Enter the value of n: ";
    cin >> n;
    
    vector<int> arr(n);  // Create a vector to store n elements
    
    cout << "Enter the values of the array:" << endl;
    for(i = 0; i < n; i++) {
        cout << "Enter the value at index " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Call the QuickSort function with the array, starting index, and ending index
    quickSort(arr, 0, arr.size() - 1);
    
    // Print the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
   
    
    return 0;  // Indicate successful execution
}


