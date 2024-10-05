//Search in Rotated Searched Array (Duplicate Values)
// for this the array must be rotated and in sorted  form Then this code return the index
//else not . like if you give arr = [7,8,9,10,1,2,3,3,4,5,2,3], target = 3. It will return element not found.
//so make sure arr should be rotated and sorted to get the index of the target.
// this code also turns into boolean format like the user can ask if the target is present in array or not
#include<bits/stdc++.h>
#include<vector>
 using namespace std;
 int findElement(vector<int> &arr,int n,int target){
    int low= 0;
    int high =n-1;
    while(low<n && arr[low]==arr[high]){
        if(arr[low]== target){
            return low;
            }
        low++;
        high--;
    }
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }else{
                
                high = mid-1;
            }
        }
    }
    return -1;
 }
 int main(){
    //Search in Rotated Searched Array (Duplicate Values)
    vector<int> arr = {7,8,9,10,1,2,3,3,4,5,6};
    int n = arr.size();
    int target = 3;
    int ans = findElement(arr,n,target);
    if (ans != -1) {
        cout <<"Element "<<target<<" found at index: " << ans+1 <<"th position."<< endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;

 }