// #include <bits/stdc++.h>
// using namespace std;

// // It starts from the second element because the first element is considered sorted.
// void insertionSort(vector<int>& arr, int n) {
//     for(int i=0;i<=n-1;i++){
//         int j=i;
//         while(j>0 && arr[j-1] > arr[j]){
//             int temp = arr[j-1];
//             arr[j-1] = arr[j];
//             arr[j] = temp;
//             j--;
//         }
//     }
//     return ;
// }

// int main() {
//     int n;
//     cout << "Enter the length of the array: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter the " << n << " elements in the array:" << endl;

//     for (int i = 0; i < n; i++) {
//         cout << "Enter element " << i + 1 << ": ";
//         cin >> arr[i];
//     }

//     // Call the insertion sort function
//     insertionSort(arr, n);

//     // Display the sorted array
//     cout << "Sorted Array: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// BELOW CODE IS THE SAME AS THE ABOVE ONE. IT'S COMPLETELY WORKING FINE ON ONLINE COMPILER BUT ITS NOT WORKING ON VS CODE, MAY BE DUE TO COMPILER ISSUE.
//LET'S TRY IT OUT.

#include <bits/stdc++.h> 
using namespace std;
void insertionSort(int n, vector<int> &arr){
    // Write your code here.

    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    return ;
}


int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements in the array:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Call the insertion sort function
    insertionSort( n,arr);

    // Display the sorted array
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
