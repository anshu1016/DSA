#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// Function to remove duplicate characters from the string
string removeDuplicates(string str, int n)
{
    // Create a set to keep track of characters we've already encountered
    unordered_set<char> seen;
    // Create a string to store the result with unique characters
    string result = "";

    // Iterate through each character in the input string
    for (int i = 0; i < n; i++) {
        // If the character has not been seen before, add it to the result
        if (seen.find(str[i]) == seen.end()) {
            result += str[i];
            seen.insert(str[i]); // Mark the character as seen
        }
    }

    return result;
}

int main() {
    // Sample Input 1
    string str1 = "abcadeecfb";
    int n1 = str1.length();
    cout << "Original: " << str1 << "\nAfter removing duplicates: " << removeDuplicates(str1, n1) << endl;

    // Sample Input 2
    string str2 = "zzzzzxx";
    int n2 = str2.length();
    cout << "Original: " << str2 << "\nAfter removing duplicates: " << removeDuplicates(str2, n2) << endl;

    return 0;
}
