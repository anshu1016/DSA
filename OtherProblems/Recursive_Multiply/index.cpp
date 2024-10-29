
// Problem statement
// You are given two positive integers. Your task is to multiply the two numbers using recursion by performing a minimum number of operations. Note that you can use addition, subtraction, and/ or bit shifting, but you cannot use the multiplication or division operation.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 10
// 1 <= M, N <= 10^8

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 5 10
// 3 9   
// Sample Output 1 :
// 50
// 27
// Explanation of sample input 1 :
// For the first test case we have, M = 5 and N = 10. Therefore our result is M*N = 5*10 = 50.

// For the second test case we have, we have M = 3 and N = 9. Therefore our result is M*N = 3*9 = 27.
// Sample Input 2 :
// 3
// 1 5
// 3 4
// 1 1
// Sample Output 2 :
// 5 
// 12
// 1
#include <bits/stdc++.h> 
using namespace std;

int recursiveProduct(int M, int N) {
    // Base cases
    if (N == 0) return 0;
    if (N == 1) return M;

    // Recursive step for even N
    if (N % 2 == 0) {
        return recursiveProduct(M << 1, N >> 1); // Double M, halve N
    } else {
        // Recursive step for odd N
        return M + recursiveProduct(M, N - 1);
    }
}

int main() {
    int T = 2;

    // Test case 1
    int M1 = 5, N1 = 10;
    cout << recursiveProduct(M1, N1) << endl; // This will print 50

    // Test case 2
    int M2 = 3, N2 = 9;
    cout << recursiveProduct(M2, N2) << endl; // This should print 27

    return 0;
}

