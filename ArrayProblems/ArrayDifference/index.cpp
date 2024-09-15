// LEETCODE QUESTION 2215
// 2215. Find the Difference of Two Arrays
// Solved
// Easy
// Topics
// Companies
// Hint
// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

 

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
// Example 2:

// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
// Explanation:
// For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
#include <iostream>
#include <vector>
#include <algorithm> // for find()

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans1;
    vector<int> ans2;

    // Iterate over nums1 and find distinct elements not in nums2
    for (int i = 0; i < nums1.size(); i++) {
        bool found = false;
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                found = true;
                break;
            }
        }
        // If not found and not already in ans1, push to ans1
        if (!found && find(ans1.begin(), ans1.end(), nums1[i]) == ans1.end()) {
            ans1.push_back(nums1[i]);
        }
    }

    // Iterate over nums2 and find distinct elements not in nums1
    for (int i = 0; i < nums2.size(); i++) {
        bool found = false;
        for (int j = 0; j < nums1.size(); j++) {
            if (nums2[i] == nums1[j]) {
                found = true;
                break;
            }
        }
        // If not found and not already in ans2, push to ans2
        if (!found && find(ans2.begin(), ans2.end(), nums2[i]) == ans2.end()) {
            ans2.push_back(nums2[i]);
        }
    }

    return {ans1, ans2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = findDifference(nums1, nums2);

    // Output the results
    cout << "Distinct elements in nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Distinct elements in nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
