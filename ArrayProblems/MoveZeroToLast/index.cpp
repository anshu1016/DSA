#include<bits/stdc++.h>
using namespace std;
int moveZeroToLast_BFT(vector<int> &arr,int n){
    vector<int> temp(n);
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp[j] = arr[i];
            j++;
        }
    }
    cout<<"PRINTING THE TEMP TO CEHCK"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<",";
    }
    //assigning the values of temp to first size of temp variables of oriignal array 
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
        
    } 
     cout<<"PRINTING THE ORIGINAL ARRAY TO CEHCK"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    // assigning the zero to remaining elements of original array;
    int noOfZeroes = temp.size();
    for(int i=noOfZeroes;i<n;i++){
        arr[i] = 0;
    }
     cout<<"PRINTING THE ORIGINAL ARRAY TO CEHCK"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }

}

int moveZeroToLast_OS(vector<int> &arr,int n){
    // if(n==0){
    //     return ;
    // }
    int j;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j=i; // we got the index of first zero value.
            break;
        }
    }

    for(int i=j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    //OUTPUT
    cout<<"PRINTING OPTIMAL SOL:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }

}

int main(){
    vector<int> arr = {1,4,2,0,0,0,64,3,0,0,0,4,2,0,32,0};
    int n= arr.size();
    moveZeroToLast_BFT(arr,n);
    moveZeroToLast_OS(arr,n);
    return 0;
}