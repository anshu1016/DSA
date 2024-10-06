// Problem statement
// You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.
// Return the number that appears once.

// Example:
// Input: 'arr' = [1,1,2,2,4,5,5]

// Output: 4 
// Explanation: 
// Number 4 only appears once the array.

// Note :
// Exactly one number in the array 'arr' appears once.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 5 
// 1 1 3 5 5 

// Sample Output 1 :
// 3 

// Explanation of Sample Input 1 :
// Given array is [1, 1, 3, 5, 5]    
// Here, 3 occurs once in the array. So, the answer is 3.

// Sample Input 2 :
// 5
// 1 1 4 4 15

// Sample Output 2 :
// 15
// Explanation of Sample Input 2 :
// The array is [1, 1, 4, 4, 15].    
// Here, 15 occurs once in the array. So, the answer is 15.

// Expected Time Complexity:
// Try to solve this in O(log(n)).

#include<bits/stdc++.h>
#include<vector>
using namespace std;
 int findSingleElement(vector<int> &arr,int n){
    if(n==0) return -1;
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-2];
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])) low = mid+1;
        else high = mid-1;
    }
    return -1;
 }
 int main(){
    vector<int> arr = {1,1,3,5,5};
    int n = arr.size();
    int singleElement = findSingleElement(arr,n);
    if(singleElement!=-1) cout<<"The only single element is: "<<singleElement<<" ."<<endl;
    else cout<<"There is no single element or the array is empty."<<endl;
    return singleElement;
 }