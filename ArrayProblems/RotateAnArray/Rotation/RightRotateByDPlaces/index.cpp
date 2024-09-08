#include<bits/stdc++.h>
using namespace std;

int rightRotateByD_BFT(vector<int> &arr,int n,int d){
    d%=n;
    vector<int> temp(n-d);
    // for(int i=n-d;i<n;i++){
    //     temp[i-(n-d)] = arr[i];
    // }
    for(int i=0;i<n-d;i++){
        temp[i] = arr[i];
    }
    // cout<<"PRINT TEMP TO CHECK IS THE VALUE STORE IN OR NOT";
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i]<<endl;
    // }
    //SHIFTING THE LAST VALUES TO START
    for(int i=n-d;i<n;i++){
        arr[i-(n-d)] = arr[i];
    }
   
    cout<<"PRINTING THE WHOLE ARRAY BY SHIFTING THE LAST n-d VALUES BY TEMP VARIABLES.";
     for(int i=d;i<n;i++){
        arr[i] = temp[i-d];
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
   

    return 0;
}
int rightRotateByD_OS(vector<int> &arr,int n, int d){
    d%=n;
    vector<int> temp(n-d);
    int i=n-d;
    int j=n-1;
    //first reverse the array from last value to till dth index.
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    for(int i=n-d;i<n;i++){
        cout<<arr[i]<<endl;
    }
    i=0;
    j=n-d-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    for(int i=0;i<n-d;i++){
        cout<<arr[i]<<endl;
    }
    i=0;
    j=n-1;
     while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    cout<<"FINAL ARRAY SHOULD BE LOOK LIKE THIS: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
int main(){
    vector<int> arr ={1,2,3,4,5,6,7,8,9,10};
    int n= arr.size();
    int d=3; // Index from which rotate the array
    //rightRotateByD_BFT(arr,n,d);
    rightRotateByD_OS(arr,n,d);
    return 0;
}