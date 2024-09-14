#include <bits/stdc++.h>
using namespace std;

int getXOR_BY_BRT(vector<int> &arr, int n) {
    for (int i = 1; i <= n; i++) { // iterate through numbers from 1 to n
        bool flag = false;
        for (int j = 0; j < arr.size(); j++) { // iterate through the entire array
            if (arr[j] == i) { // check if i exists in the array
                flag = true; // found the number, set flag to true
                break;
            }
        }
        if (!flag) {
            return i; // if i is not found, return i
        }
    }
    return n; // if all numbers from 1 to n are found, return n

    // TC = O(N*N)
    // SC = O(1)
}
int getXOR_BY_BS(vector<int> &arr, int n) {
    vector<int> hash(n + 1, 0); // Create a hash table initialized with 0's

    // Mark the numbers that exist in the array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= n) { // Only mark numbers <= n
            hash[arr[i]] = 1;
        }
    }

    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) { // If a number is missing in the hash table
            return i;
        }
    }

    return -1; // Return -1 if no number is missing

    //TC = O(N+N)
    //SC = O(N)
}

int getXOR_By_OL_1(vector<int> &arr, int n) {
    int sum = (n * (n + 1)) / 2;  // Sum of numbers from 1 to n
    int s2 = 0;
    
    // Loop through the array, summing its elements
    for (int i = 0; i < arr.size(); i++) {
        s2 += arr[i];
    }
    
    // Return the difference between expected sum and array sum
    return sum - s2;  // This will give the missing number
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 7, 8, 9, 10};  // Array with a missing number
    int missingNumberByBRT = getXOR_BY_BRT(arr, 10); // brute force
    cout << "The missing number by BRT technique is: " << missingNumberByBRT << endl;
    
    int missingNumberByBetterSol = getXOR_BY_BS(arr, 10); // using hash table
    cout << "The missing number by Better Solution is: " << missingNumberByBetterSol << endl;

    int missingNumberByOptimalSol_By_OL1 = getXOR_By_OL_1(arr, 10); // using sum formula
    cout << "The missing number by OL1 technique is: " << missingNumberByOptimalSol_By_OL1 << endl;

    return 0;
}
