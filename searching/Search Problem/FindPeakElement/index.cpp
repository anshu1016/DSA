// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

#include<bits/stdc++.h>
#include<vector>
using namespace std;
int findPeakIndex(vector<int> &arr,int n){
    if(n==0) return -1;
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]) low = mid+1;
        else if(arr[mid]>arr[mid+1]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int main(){
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int n = arr.size();
    int index = findPeakIndex(arr,n);
    if(index!=-1) cout<<"peak element at "<<index<<" index.";
    else cout<<"There is no peak element.";    
    return index;
}