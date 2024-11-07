#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int countOfCows = 1;
    int lastCow = stalls[0];
    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - lastCow >= dist) {
            countOfCows++;
            lastCow = stalls[i];
        }
        if(countOfCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canWePlace(stalls, mid, k)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    // Predefined input
    vector<int> stalls = {1, 2, 4, 8, 9, 12, 16, 20, 25, 30, 35, 40, 50, 60, 70};
    int k = 4;  // Number of cows

    // Calling the aggressiveCows function
    int result = aggressiveCows(stalls, k);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
