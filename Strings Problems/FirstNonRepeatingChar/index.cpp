#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeatingCharacter(const string& str) {
    unordered_map<char, int> freqMap;
    
    // Step 1: Count frequencies of all characters
    for (char ch : str) {
        freqMap[ch]++;
    }
    
    // Step 2: Find the first character with frequency 1
    for (char ch : str) {
        if (freqMap[ch] == 1) {
            return ch;
        }
    }
    
    // Step 3: If no non-repeating character is found
    return '-';
}

int main() {
    string str = "geeksforgeeks";
    
    char result = firstNonRepeatingCharacter(str);
    
    if (result != '-') {
        cout << "The first non-repeating character is: " << result << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }
    
    return 0;
}
