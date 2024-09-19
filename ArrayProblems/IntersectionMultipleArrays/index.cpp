#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge two halves of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on an array
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to find common elements in all subarrays
vector<int> findCommonElements(vector<vector<int>>& nums) {
    int totalArrays = nums.size();

    // Step 1: Sort each subarray using merge sort
    for (auto& subarray : nums) {
        mergeSort(subarray, 0, subarray.size() - 1);
    }

    // Step 2: Initialize the common elements from the first sorted subarray
    vector<int> commonElements = nums[0];

    // Step 3: Find common elements across all arrays using two-pointer technique
    for (int i = 1; i < totalArrays; i++) {
        vector<int> temp;
        int p1 = 0, p2 = 0;

        while (p1 < commonElements.size() && p2 < nums[i].size()) {
            if (commonElements[p1] == nums[i][p2]) {
                temp.push_back(commonElements[p1]);
                p1++;
                p2++;
            } else if (commonElements[p1] < nums[i][p2]) {
                p1++;
            } else {
                p2++;
            }
        }

        commonElements = temp;  // Update the common elements
        if (commonElements.empty()) {
            break;  // No common elements
        }
    }

    return commonElements;
}

int main() {
    // Example 1
    vector<vector<int>> nums1 = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};
    vector<int> result1 = findCommonElements(nums1);
    cout << "Output for example 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> nums2 = {{1, 2, 3}, {4, 5, 6}};
    vector<int> result2 = findCommonElements(nums2);
    cout << "Output for example 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
