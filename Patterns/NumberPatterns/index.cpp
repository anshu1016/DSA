#include <iostream>
using namespace std;

int main() {
    int N=10;

    for (int i = 1; i <= N; i++) {
        cout << "1";  // Print the first '1' in each row
        for (int j = 1; j < i - 1; j++) {
            cout << "2";  // Print '2' for the middle elements
        }
        if (i > 1) {
            cout << "1";  // Print the last '1' if row number > 1
        }
        cout << endl;  // Move to the next line after each row
    }

    return 0;
}


// Problem statement
// Print the following pattern for the given N number of rows.

// Pattern for N = 4
// 1
// 11
// 121
// 1221