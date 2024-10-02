#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the lower bound
int lower_bound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Function to find the upper bound
int upper_bound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Function to insert an element while maintaining sorted order
vector<int> insert_and_sort(vector<int> arr, int target) {
    int pos = lower_bound(arr, target);
    arr.insert(arr.begin() + pos, target);
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int target = 4;

    int lower = lower_bound(arr, target);
    int upper = upper_bound(arr, target);

    cout << "Lower Bound of " << target << ": " << lower << endl;
    cout << "Upper Bound of " << target << ": " << upper << endl;

    // Insert target and maintain sorted order
    arr = insert_and_sort(arr, target);

    cout << "Array after insertion: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
