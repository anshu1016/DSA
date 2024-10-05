//Find Minimum in rotated search array (Uniqu Elements)
//for this the array must be rotated and in sorted  form Then this code return the index
//else not . like if you give arr = [7,8,9,10,1,2,3,3,4,5,2,3], target = 3. It will return element not found.
//so make sure arr should be rotated and sorted to get the index of the target.
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int findMin(vector<int> &arr,int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    if(n==0){
        return -1;
    }
    while(low<=high){
        int mid = low+(high-low)/2;
        // if(arr[mid] == ans){
        //     return arr[mid];
        // }
        if(arr[low] <= arr[high]){
            ans = min(ans,arr[low]);
            break;           
        }
        if(arr[low]<=arr[mid]){
            ans = min(ans,arr[low]);
            low = mid+1;
        }else{
            high = mid-1;
            ans = min(ans,arr[mid]);
        }
    }
    return ans;
}
int findMinII(vector<int> &arr,int n){
    int low = 0;
    int high = n-1;
    int min = INT_MAX;
    while(low<=high){
        int mid  = (low+high)/2;
        if(mid>0 && mid<n-1&&arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1]){
            return arr[mid];
        }else if(arr[mid]>=arr[high]){
            low++;
        }else{
            high--;
        }
    }
    return low;
}
int main(){
    vector<int> arr = {7,8,9,10,-1,0,1,2,3,3,4,5,6};
    int n = arr.size();
    int minimumValue = findMin(arr,n);
    int minimumValueII = findMinII(arr,n);
   
        cout <<"Minimum Value from I  : "<<minimumValue<<" and Minimum Value from II is : "<<minimumValueII<< endl;
    
    return 0;
}