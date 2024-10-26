#include <iostream>
#include <vector>
using namespace std;

bool validUtf8(vector<int> &data) {
    int bytesToProcess = 0;

    for (int byte : data) {
        if (bytesToProcess == 0) {
            if ((byte >> 5) == 0b110) {
                bytesToProcess = 1;
            } else if ((byte >> 4) == 0b1110) {
                bytesToProcess = 2;
            } else if ((byte >> 3) == 0b11110) {
                bytesToProcess = 3;
            } else if ((byte >> 7)) {
                // 1-byte character must start with a 0 in the most significant bit
                return false;
            }
        } else {
            // Check if the current byte is a valid continuation byte
            if ((byte >> 6) != 0b10) {
                return false;
            }
            bytesToProcess--;
        }
    }

    return bytesToProcess == 0;
}

int main() {
    vector<vector<int>> testCases = {
        {232, 136, 4},
        {196, 128, 1},
        {255},
        {197, 130, 1}
    };

    for (int t = 0; t < testCases.size(); t++) {
        bool result = validUtf8(testCases[t]);
        cout << "Test case " << t + 1 << ": " << (result ? "true" : "false") << endl;
    }

    return 0;
}
