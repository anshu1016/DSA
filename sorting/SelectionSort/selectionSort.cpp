#include <bits/stdc++.h>
using namespace std;

// SELECTION_SORT = get Minimum & SWAP.
//TIME_COMPLEXITY = O(n2) this is the best,average and worst time complexity.



void selection_Sort(vector<int>& arr, int n) {
     for(int i = 0; i < n - 1; i++) {
            int mini = i;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[mini]) {
                    mini = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            if(mini != i) {
                int temp = arr[i];
                arr[i] = arr[mini];
                arr[mini] = temp;
            }
        }
}

int main() {
    int n;
    cout << "Enter the length of an array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements in the array:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Call the selection sort function
    selection_Sort(arr, n);

    // Display the sorted array
    cout << "Sorted Array will be: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
