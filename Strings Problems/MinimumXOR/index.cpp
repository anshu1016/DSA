#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findMinXORValue(const vector<int>& arr) {
    int minXor = INT_MAX;
    int n = arr.size();

    // Sort the array
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    // Calculate XOR for consecutive pairs
    for (int i = 0; i < n - 1; i++) {
        int xorValue = sortedArr[i] ^ sortedArr[i + 1];
        minXor = min(minXor, xorValue);
    }

    return minXor;
}

int main() {
    // Predefined input
    int T = 2;
    vector<vector<int>> testCases = {
        {13, 5, 11, 1},
        {0, 5, 2, 7}
    };

    for (int i = 0; i < T; i++) {
        int result = findMinXORValue(testCases[i]);
        cout << result << endl;
    }

    return 0;
}
