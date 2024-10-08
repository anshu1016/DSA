// Problem statement
// A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

// Example:
// Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7
// Output: 3
// Explanation: If ‘m’ = 3, then 
// The time taken to empty the 1st pile is 1 hour.
// The time taken to empty the 2nd pile is 2 hour.
// The time taken to empty the 3rd pile is 1 hour.
// The time taken to empty the 4th pile is 3 hour.
// Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.


#include <iostream>
#include <vector>
#include <cmath> // for ceil

using namespace std;

// Function to find the maximum value in the array
int findMax(vector<int> &v) {
    int max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

// Function to calculate the total hours required to eat all the piles at speed 'mid'
long long calculateTotalHour(vector<int> &v, int mid) {
    long long totalH = 0; // Use long long to avoid overflow
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)v[i] / (double)mid);
    }
    return totalH;
}

// Function to find the minimum eating speed
int minimumRateToEatBananas(vector<int> &v, int h) {
    int low = 1;
    int high = findMax(v);
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long totalHour = calculateTotalHour(v, mid); 
        
        if (totalHour <= h) {
            high = mid - 1; // Try a smaller speed //eleminta right
        } else {
            low = mid + 1;  // Increase the speed // eliminate left
        }
    }
    return low;
}

int main() {
    vector<int> piles = {805306368, 805306368, 805306368};
    
    long long h = 1000000000;
    
    // cout << "Enter number of piles: ";
    // cin >> n;
    // piles.resize(n);
    
    // cout << "Enter the piles: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> piles[i];
    // }
    
    // cout << "Enter number of hours: ";
    // cin >> h;

    int result = minimumRateToEatBananas(piles, h);
    cout << "Minimum eating speed to finish in " << h << " hours: " << result << endl;

    return 0;
}
