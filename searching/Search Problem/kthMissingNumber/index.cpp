#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return k + high + 1;
    }
};

int main() {
    vector<int> arr = {2, 3, 4, 7, 11, 18, 21, 24, 30, 35, 50, 62, 75, 80, 99};
    int k = 15;

    Solution solution;
    int result = solution.findKthPositive(arr, k);

    cout << "Output: " << result << endl;

    return 0;
}


// Problem statement
// You are given a strictly increasing array 'vec' and a positive integer 'k'.



// Find the 'kth' positive integer missing from 'vec'.



// Example :
// Input: vec = [2,4,5,7] , k = 3

// Output: 6

// Explanation : 
// In the given example, first missing positive integer is 1 second missing positive integer is 3, and the third missing positive integer is 6.
// Hence the answer is 6. 


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 4
// 4 7 9 10
// 1


// Sample Output 1 :
// 1


// Explanation For Sample Input 1 :
// The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on.
// Since 'k' is 1, the first missing element is 1.


// Sample Input 2 :
// 4
// 4 7 9 10
// 4


// Sample Output 2 :
// 5
