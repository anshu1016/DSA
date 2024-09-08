#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesByOptimalApproach(vector<int> &arr) {
    if (arr.size() == 0) return 0;  // Handle empty array case
    
    int i = 0;
    for (int j = 1; j < arr.size(); j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];  // Move the next unique element to position i
        }
    }
    return i + 1;  // Length of the unique array
}
int removeDuplicatesByBFApproach(vector<int> &arr){
set<int> st;
for(int i=0;i<arr.size();i++){
    st.insert(arr[i]);
}
return st.size();
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 4, 5, 5};  // Example sorted input array
    int k = removeDuplicatesByOptimalApproach(arr);
    int x = removeDuplicatesByBFApproach(arr);
    // Output the first k unique elements
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < x; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
