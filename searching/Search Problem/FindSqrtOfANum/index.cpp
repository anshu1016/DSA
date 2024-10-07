#include<bits/stdc++.h>
using namespace std;

int findSquareRoot(int x){
    int low =1;
    int high = x;
    if(x<0) return -1;
    if(x==0) return 0;    
    while(low<=high){
        int mid = low+(high-low)/2;
        if((mid*mid)<=x) low = mid + 1 ;
        else high = mid - 1 ;
    }
    return high;
}
int main(){
    int x = -2;
    int sqrt = findSquareRoot(x);
    cout<<"The Square Root of  "<<x<<" is: "<<sqrt<<endl;
    return sqrt;
}