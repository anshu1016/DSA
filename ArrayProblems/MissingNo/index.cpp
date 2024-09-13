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
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    int missingNumberByBRT = getXOR_BY_BRT(arr, 10); // looking for numbers between 1 and 10
    cout << "The missing number by bRT techniqeis: " << missingNumberByBRT << endl;
    
    int missingNumberByBetterSol = getXOR_BY_BS(arr,10);
    cout<<"THe Missing no. in the series missingNumberByBetterSol ie:"<<missingNumberByBetterSol;
    return 0;
}
