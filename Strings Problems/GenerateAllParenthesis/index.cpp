#include <iostream>
using namespace std;

void generateParentheses(int open, int close, string current, int n) {
    // Base case: If the current string has reached the required length, print it
    if (current.length() == 2 * n) {
        cout << current << endl;
        return;
    }

    // If we can still add an open parenthesis, do so
    if (open < n) {
        generateParentheses(open + 1, close, current + "(", n);
    }

    // If we can add a close parenthesis without breaking the balance, do so
    if (close < open) {
        generateParentheses(open, close + 1, current + ")", n);
    }
}

void printWellFormedParanthesis(int n) {
    generateParentheses(0, 0, "", n);
}

int main() {
    int n=10;
    printWellFormedParanthesis(n);
    return 0;
}
