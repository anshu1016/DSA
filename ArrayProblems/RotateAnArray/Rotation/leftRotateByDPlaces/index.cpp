#include<bits/stdc++.h>
using namespace std;

int leftRotateByDPlacesOS(vector<int> &arr,int d){
    int n = arr.size();
    d=d%n;
    int i=0;
    int j= d-1;
    //reverse the array till d;
    while(i<d && j>0){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    cout<<"REVERSED TILL D"<<endl;;
    for(i=0;i<d;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"REVERSE AFTER D TILL END"<<endl;
   i=d;
   j=n-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
    for(int k=d;k<n;k++){
        cout<<arr[k]<<" ";
    }

    cout<<"Now Reversing the whole array to get the desired output."<<endl;
    int x=0;
    int y=n-1;
    while(x<y){
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
        x++;
        y--;
    }
    cout<<"AFTER REVERSING THE WHOLE ARRAy. DESIRED OUTPUT WILL BE"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    //TC = O(d) + O(n-d) +O(n) = O(2n) increases from BFT
    //SC = O(1) //nice than BFT.
}

int leftRotateByDPlacesBFT(vector<int> &arr,int d) //BRUTE-FORCE TECHNIQUE
{
    vector<int> temp(d);
    int n= arr.size();
    d%=n;
   
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
     }
    for(int i = d;i<n;i++){
        arr[i-d] = arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)];
    }
     for(int i=0;i<arr.size();i++){
        
        cout<<arr[i]<<" ";
    }
    //TC = O(d)+O(n-d)+O(d) = O(n+d);
//SC = O(d) we are taking extra temp 
    
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int d;
    cout<<"Enter the number you want to rotate the array:  ";
    cin>>d;
    // leftRotateByDPlacesBFT(arr,d);
    leftRotateByDPlacesOS(arr,d);
    return 0;
}