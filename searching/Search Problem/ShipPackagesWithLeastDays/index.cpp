#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the maximum weight in the weights array
    int findMax(const vector<int>& weights) {
        int maxWeight = 0;
        for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
        }
        return maxWeight;
    }

    // Function to find the sum of all weights in the weights array
    int findSum(const vector<int>& weights) {
        int totalWeight = 0;
        for (int weight : weights) {
            totalWeight += weight;
        }
        return totalWeight;
    }

    // Function to calculate the number of days required to ship all weights with the given capacity
    int findNoOfDays(const vector<int>& weights, int capacity) {
        int days = 1; // Start with one day
        int currentLoad = 0;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                // Need a new day if the current load exceeds the capacity
                days++;
                currentLoad = weight; // Start a new load with the current weight
            } else {
                currentLoad += weight;
            }
        }
        return days;
    }

    // Binary search to find the minimum weight capacity to ship all packages within 'd' days
    int binarySearchForCapacity(const vector<int>& weights, int d, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int requiredDays = findNoOfDays(weights, mid);

            if (requiredDays <= d) {
                high = mid - 1; // Try to find a smaller capacity
            } else {
                low = mid + 1; // Increase the capacity
            }
        }
        return low; // The minimum capacity to ship within 'd' days
    }

    // Main function to find the least weight capacity required
    int leastWeightCapacity(vector<int>& weights, int d) {
        int low = findMax(weights); // The minimum capacity must be at least the heaviest package
        int high = findSum(weights); // The maximum capacity can be the sum of all weights
        return binarySearchForCapacity(weights, d, low, high);
    }
};

// Main function with predefined inputs
int main() {
    // Predefined input values
    int n = 5; // Number of weights
    int d = 3; // Number of days
    vector<int> weights = {1, 2, 3, 4, 5}; // Weights of the packages

    Solution solution;
    int result = solution.leastWeightCapacity(weights, d);
    
    // Output: minimum weight capacity needed
    cout << "Least weight capacity to ship within " << d << " days: " << result << endl;

    return 0;
}
