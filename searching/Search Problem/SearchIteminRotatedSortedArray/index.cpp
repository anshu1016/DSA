#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n - 1;
    
    if (n == 0) {
        return -1;
    }
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == k) {
            return mid;
        }
        
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int target = 0;
    
    int result = search(arr, n, target);
    
    if (result != -1) {
        cout << "Element " << target << " is at index " << result << endl;
    } else {
        cout << "Element " << target << " is not found in the array" << endl;
    }
    
    return 0;
}


//TC will be O(lon N) because it taking a binary search for its operations.