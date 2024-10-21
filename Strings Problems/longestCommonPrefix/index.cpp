#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Start with the first string as the prefix
    string prefix = strs[0];
    
    // Compare the prefix with each string in the array
    for (int i = 1; i < strs.size(); i++) {
        // Reduce the prefix size until it matches the current string
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return ""; // If no common prefix, return empty string
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl; // Output: "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}
