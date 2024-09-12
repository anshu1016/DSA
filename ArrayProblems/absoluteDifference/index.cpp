// Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

// The value of |x| is defined as:

// x if x >= 0.
// -x if x < 0.
 

// Example 1:

// Input: nums = [1,2,2,1], k = 1
// Output: 4
// Explanation: The pairs with an absolute difference of 1 are:
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// Example 2:

// Input: nums = [1,3], k = 3
// Output: 0
// Explanation: There are no pairs with an absolute difference of 3.
#include<bits/stdc++.h>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the absolute difference between nums[i] and nums[j] is k
            if (abs(nums[i] - nums[j]) == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 1;
    cout << "Count of pairs with difference " << k1 << ": " 
         << countKDifference(nums1, k1) << endl;  // Output: 3

    // Test case 2
    vector<int> nums2 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int k2 = 2;
    cout << "Count of pairs with difference " << k2 << ": " 
         << countKDifference(nums2, k2) << endl;  // Output: 8

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 1};
    int k3 = 2;
    cout << "Count of pairs with difference " << k3 << ": " 
         << countKDifference(nums3, k3) << endl;  // Output: 2

    return 0;
}
