#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countSwaps(string str) {
    int n = str.size();
    int swaps = 0;
    int left = 0, right = n - 1;

    // Check if the string can be a palindrome by counting character frequencies
    vector<int> charCount(26, 0);
    for (char c : str) {
        charCount[c - 'a']++;
    }
    int oddCount = 0;
    for (int count : charCount) {
        if (count % 2 != 0) {
            oddCount++;
        }
    }
    // If more than one character has an odd frequency, it's impossible to make it a palindrome
    if (oddCount > 1) {
        return -1;
    }

    // Try to make the string a palindrome using adjacent swaps
    while (left < right) {
        if (str[left] == str[right]) {
            left++;
            right--;
        } else {
            int k = right;
            // Find the matching character for str[left] from the right side
            while (k > left && str[k] != str[left]) {
                k--;
            }

            if (k == left) {
                // If no matching character is found, swap str[left] with str[left + 1]
                swap(str[left], str[left + 1]);
                swaps++;
            } else {
                // Move the matching character to the correct position by swapping adjacent elements
                while (k < right) {
                    swap(str[k], str[k + 1]);
                    swaps++;
                    k++;
                }
                left++;
                right--;
            }
        }
    }
    return swaps;
}

int main() {
    // Predefined input examples
    string str1 = "mamad";
    string str2 = "abc";

    // Output for the first input
    cout << "Number of swaps for \"" << str1 << "\": " << countSwaps(str1) << endl;
    
    // Output for the second input
    cout << "Number of swaps for \"" << str2 << "\": " << countSwaps(str2) << endl;

    return 0;
}
