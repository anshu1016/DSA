#include <iostream>
#include <cstring>

void reverseStringWordWise(char input[]) {
    int len = strlen(input);
    int start = 0, end = len - 1;

    // Step 1: Reverse the entire string
    while (start < end) {
        std::swap(input[start], input[end]);
        start++;
        end--;
    }

    // Step 2: Reverse each word individually
    start = 0;
    for (int i = 0; i <= len; i++) {
        // If we find a space or reach the end of the string
        if (input[i] == ' ' || input[i] == '\0') {
            end = i - 1;
            // Reverse the current word
            while (start < end) {
                std::swap(input[start], input[end]);
                start++;
                end--;
            }
            start = i + 1; // Move to the start of the next word
        }
    }
}

int main() {
    // Predefined input
    char input[] = "Welcome to Coding Ninjas";

    // Call the function
    reverseStringWordWise(input);

    // Output the result
    std::cout << input << std::endl;

    return 0;
}
