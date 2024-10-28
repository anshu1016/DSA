#include <bits/stdc++.h> 
using namespace std;

void printPattern(int n) {
    for (int i = 0; i < n; ++i) {
        // Print spaces
        for (int j = 0; j < n - i - 1; ++j) {
            cout << " ";
        }
        // Print stars
        for (int k = 0; k < (2 * i + 1); ++k) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int T = 8;
    
    while (T--) {
        int N;
        cin >> N;
        printPattern(N);
    }
    return 0;
}
