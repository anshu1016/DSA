#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (nums[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (nums[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target is not present in the array
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = binarySearch(nums, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in array" << endl;

    return 0;
}
