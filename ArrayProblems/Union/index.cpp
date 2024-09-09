#include<bits/stdc++.h>
using namespace std;
int unionOfBoth_BFT(vector<int> arr1,vector<int> arr2){
    set<int> st;
    int n1 = arr1.size();
    int n2 = arr2.size();
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }//TC for this step =  O(n1logn)
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    } //TC for this step  O(n2logn)
    vector<int> unionArr(st.size());
    int index = 0;
    for(auto it : st){
        unionArr[index] = it;
        index++;
    } // TC for this step = O(n1+n2)
    cout<<"Output will be"<<endl;
    for(int i=0;i<unionArr.size();i++){
        cout<<unionArr[i]<<" ";
    }
    //TC = O(n1logn) + O(n2logn) + O(n1+n2)
    //SC = O(n1+n2)(this is for set if all are different) + O(n1+n2)//this is for just return the answer not storing 
}

int unionOfBoth_OS(vector<int> &arr1,vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0,j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }else{
             if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
          if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
    }

    while(j<n2){
         if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
    }
    cout<<"Output of Optimal Solution will be: "<<endl;
    for(int i=0;i<unionArr.size();i++){
        cout<<unionArr[i]<<" ";
    }
    return 0;
}
int main(){
    vector<int> arr1 = {1,2,3,3,4,5,5,6};
    vector<int> arr2 = {2,3,3,5,6,6,7,8,9,10,11,12};
    // unionOfBoth_BFT(arr1,arr2);
    unionOfBoth_OS(arr1,arr2);
    return 0;
}