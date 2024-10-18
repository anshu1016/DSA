#include <iostream>
#include <sstream>  // For std::istringstream
using namespace std;

string findLongestWord(const string& sentence) {
    istringstream stream(sentence);
    string word, longestWord = "";
    
    while (stream >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    
    return longestWord;
}

int main() {
    string sentence = "The quick brown fox jumped over the lazy dog";
    
    string longestWord = findLongestWord(sentence);
    
    cout << "The longest word is: " << longestWord << endl;
    
    return 0;
}
