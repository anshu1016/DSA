#include <iostream>
#include <unordered_set>
using namespace std;

int longestSubstringWithoutRepeatingChars(const string& str) {
    unordered_set<char> charSet;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < str.length(); ++right) {
        while (charSet.find(str[right]) != charSet.end()) {
            charSet.erase(str[left]);
            ++left;
        }
        charSet.insert(str[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string str = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " 
         << longestSubstringWithoutRepeatingChars(str) << endl;
    return 0;
}
