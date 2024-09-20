// Problem Description:
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// Explanation:

// Intervals [1, 3] and [2, 6] overlap, so they are merged into [1, 6].
// The rest do not overlap, so they remain unchanged.
// Approach:
// Sort the intervals based on the starting time.
// Iterate through the sorted intervals and merge the current interval with the previous one if they overlap.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Sort intervals based on the starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    
    for (const auto& interval : intervals) {
        // If merged is empty or the current interval does not overlap with the previous
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval); // add the current interval
        } else {
            // If there is an overlap, merge the intervals
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    
    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = mergeIntervals(intervals);
    
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
