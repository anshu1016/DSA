#include<bits/stdc++.h>
using namespace std;

int intersectionOfBothArr_BFT(vector<int> &arr1, vector<int> &arr2) {
    vector<int> answer;
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    // Initialize visited array of the size of arr2
    vector<int> visited(n2, 0);  // Size n2, initialized with 0s

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            // Check for match and ensure the element in arr2 hasn't been visited
            if (arr1[i] == arr2[j] && visited[j] == 0) {
                answer.push_back(arr1[i]);  // Add to the answer
                visited[j] = 1;             // Mark as visited
                break;                      // Break after finding the first match for arr1[i]
            }
        }
        //TC = O(n1 * n2)
        //SC = O(n2) // for small array we have visited array. that's why SC is minimum.
    }

    // Print the intersection result
    cout << "Output of Intersection will be: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
int intersectionOfBothArr_OS(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0;
    int j=0;
    vector<int> answer;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            answer.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    cout<<"Output of Optimal Solution will be: "<<endl;
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    // TC = O(n1+n2)
    // Sc = O(1)
}

int main() {
    vector<int> arr1 = {1, 2, 3, 3, 4, 5, 5, 6};
    vector<int> arr2 = {2};

    intersectionOfBothArr_BFT(arr1, arr2);
    intersectionOfBothArr_OS(arr1,arr2);
    return 0;
}
