#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={3,2,3,-3,2,4,5};
    int x = 3; //Element to search
    for(int i=0;i<arr.size();i++){
        if(arr[i] == x){
            cout<<"X found at : "<<i<<endl;
        }
    }
    return 0;
}