#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // Ignore non-alphanumeric characters and case sensitivity
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;
        
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    // std::string input;
    // std::cout << "Enter a string: ";
    // std::getline(std::cin, input);
    std::string input = "A man, a plan, a canal, Panama";
    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
