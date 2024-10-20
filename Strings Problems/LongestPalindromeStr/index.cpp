#include <iostream>
#include <string>
using namespace std;

// Function to expand around center and return the length of the palindrome
int expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // Return length of palindrome
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {
        // Case 1: Odd-length palindromes (single center character)
        int len1 = expandAroundCenter(s, i, i);
        // Case 2: Even-length palindromes (two center characters)
        int len2 = expandAroundCenter(s, i, i + 1);

        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Longest palindromic substring: " << longestPalindrome(s) << endl;
    return 0;
}
