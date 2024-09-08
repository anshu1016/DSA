#include<bits/stdc++.h>
using namespace std;

int leftRotate(vector<int> &arr){
    
    int temp = arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1] = arr[i]; 
    }
    
    arr[arr.size()-1] = temp;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int rightRotate(vector<int> &arr){
    // if(arr.size() == 0) return;
int temp = arr[arr.size()-1];
int n= arr.size();
for(int i=n-1;i>0;i--){
    arr[i] = arr[i-1];
}
arr[0] = temp;
for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
return 0;

}
int main(){
    vector<int> arr={1,2,3,4,5};
    leftRotate(arr);
    rightRotate(arr);
    
    return 0;
}