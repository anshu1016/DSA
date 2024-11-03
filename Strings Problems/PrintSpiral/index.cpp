#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols) {
    if (nRows == 0 || nCols == 0) {
        return;
    }

    int top = 0, bottom = nRows - 1;
    int left = 0, right = nCols - 1;

    while (top <= bottom && left <= right) {
        // Print the top row (left to right)
        for (int i = left; i <= right; i++) {
            cout << input[top][i] << " ";
        }
        top++; // Move the top boundary down

        // Print the right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            cout << input[i][right] << " ";
        }
        right--; // Move the right boundary left

        // Print the bottom row (right to left) if still within boundaries
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << input[bottom][i] << " ";
            }
            bottom--; // Move the bottom boundary up
        }

        // Print the left column (bottom to top) if still within boundaries
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << input[i][left] << " ";
            }
            left++; // Move the left boundary right
        }
    }
    cout << endl; // Move to the next line after printing the spiral
}

int main() {
    int t = 1; // Number of test cases

    while (t--) {
        int nRows = 5, nCols = 6;

        // Predefined values for the 2D array
        int predefined[5][6] = {
            {1, 2, 3, 4, 5, 6},
            {7, 8, 9, 10, 11, 12},
            {13, 14, 15, 16, 17, 18},
            {19, 20, 21, 22, 23, 24},
            {25, 26, 27, 28, 29, 30}
        };

        // Dynamically allocate the 2D array
        int **input = new int*[nRows];
        for (int i = 0; i < nRows; i++) {
            input[i] = new int[nCols];
            for (int j = 0; j < nCols; j++) {
                input[i][j] = predefined[i][j]; // Assign predefined values
            }
        }

        // Call the function to print in spiral order
        spiralPrint(input, nRows, nCols);

        // Free the dynamically allocated memory
        for (int i = 0; i < nRows; i++) {
            delete[] input[i];
        }
        delete[] input;
    }

    return 0;
}
