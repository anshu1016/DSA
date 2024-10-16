#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    vector<string> words;  // Vector to store the words
    stringstream ss(s);     // String stream for splitting the string
    string word;

    // Extract each word and store it in the vector
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Join the reversed words into a single string
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";  // Add space between words
        }
    }

    return result;
}

int main() {
    string s = "the sky is blue";
    cout << "Original string: " << s << endl;

    string reversed = reverseWords(s);
    cout << "Reversed words: " << reversed << endl;

    return 0;
}
