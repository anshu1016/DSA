#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int first = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1;  // Move left to find the first occurrence
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return first;
}

int lastOccurence(vector<int> &arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int last = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1;  // Move right to find the last occurrence
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return last;
}

pair<int, int> firstAndLastOccurence(vector<int> &arr, int n, int x) {
    int first = firstOccurence(arr, n, x);
    
    if (first == -1) {
        return {-1, -1};
    }
    
    int last = lastOccurence(arr, n, x);
    return {first, last};
}

int count(vector<int> &arr, int n, int x) {
    if (arr.size() == 0) {
        return 0;
    }
    
    pair<int, int> ans = firstAndLastOccurence(arr, n, x);
    
    if (ans.first == -1) {
        return 0;
    }
    
    return ans.second - ans.first + 1;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};  // Test case
    int n = arr.size();
    int x = 2;
    
    int result = count(arr, n, x);
    cout << "Count of " << x << " is: " << result << endl;
    
    return 0;
}
//TC = O(logn) because all are taking binary search so the overall combine TC is O(log n) 
// All are constant variables so SC is O(1);