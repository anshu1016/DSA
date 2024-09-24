#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& nums,int low,int high, int target) {
    
    if(low>high){
        return -1;
    }
    int mid = low+(high-low)/2; // for large dataset suppose low and high = int_max so if u r doing (low+high) /2 it means first you have to store low+high which is generally 2 Int_MAX and it is impossible to store in int. So if you have large dataset then u can use long to store instead of INT else use this logic low+(high-low)/2 = (2low+high-low)/2 = (high-low)/2
    if(nums[mid] == target){
        return mid;
    }
    else if(target>nums[mid]){
        return binarySearch(nums,mid+1,high,target);
    }else{
        return binarySearch(nums,low,mid-1,target);
    }

    // Target is not present in the array
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = -1;
    int low = 0;
    int high = nums.size()-1;
    int result = binarySearch(nums, low,high,target);
    cout<<"the target is found at : "<<result<<" th place"<<endl;
    return result;
}
