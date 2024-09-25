#include <iostream>
using namespace std;

int searchInsert(int nums[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int nums[] = {1, 3, 5, 6}; // Example array
    int target = 5; // Example target
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = searchInsert(nums, n, target);
    cout << "Index to insert target: " << result << endl;

    return 0;
}

//SC = O(log2n)