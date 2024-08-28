//PUSH THE MAXIMUM TO THE LAST BY THE ADJACENT SWAPS.
//THE WORST & AVERAGE TIME_COMPLEXITY is O(n^2) and BEST is O(n) because the best is that the given array is already sorted.
#include <bits/stdc++.h>
using namespace std;

void bubble_Sort(vector<int>& arr, int n){
    for(int i =n-1;i>=0;i--){
        int didSwap = 0; //optimization for best swap
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap =1;
            }
        }
        if(didSwap == 0){
            break;
        }
        cout<<"runs\n";
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
    bubble_Sort(arr, n);

    // Display the sorted array
    cout << "Bubble Sorted Array will be: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
