#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    // Step 1: Use a stringstream to split words
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words and store them in a vector
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Reverse the words vector
    reverse(words.begin(), words.end());

    // Step 3: Join words with a single space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string s = "  hello   world  ";
    cout << "Original string: \"" << s << "\"" << endl;
    string reversed = reverseWords(s);
    cout << "Reversed words string: \"" << reversed << "\"" << endl;
    return 0;
}
