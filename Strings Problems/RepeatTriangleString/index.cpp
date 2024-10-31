#include <bits/stdc++.h> 
using namespace std;

vector<string> repeatTriangle(int n) {
    vector<string> result;

    for (int i = 0; i < n; i++) {
        string row;

        // Add leading spaces to create the triangle effect
        row += string(i, ' ');

        // Build the left half of the row (increasing characters from 'A')
        for (int j = 0; j < n - i; j++) {
            row += char('A' + j);
        }

        // Build the right half of the row (decreasing characters back to 'A')
        for (int j = n - i - 1; j >= 0; j--) {
            row += char('A' + j);
        }

        result.push_back(row);
    }

    return result;
}

int main() {
    int t=7;
    
    while (t--) {
        int n=5;
        
        vector<string> pattern = repeatTriangle(n);
        for (string line : pattern) {
            cout << line << endl;
        }
    }
    return 0;
}
