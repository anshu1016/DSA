#include<bits/stdc++.h>
using namespace std;

int doPartition(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){ // check the condition if i < j then we can run this code.
        while(arr[i] <= pivot && i<=high-1){ // here we are compairing the <= because we want all smaller values or the same vallues on left side and we are moving the i pointer towards right until i<=high-1 fails.
            i++;
        }
        while(arr[j] >= pivot && j>=low+1){ // here we are compairing the >= because we want all tthe greater on the right side and move the pointer towards left until j>=low+1 conditoin fails.
            j--;
        }
        if(i<j){ // so, in last if we are swapping the i and jth pointer values so we can say that here greaer comes in right side and smaller comes in left side. 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }
    int temp = arr[j]; // At in the last we are again swapping because we have to wap the ppivot value with jth. Because this is the step where our array permanently divides in partition teritory region because due to swap of pivot with j ensures that pivot comes at righjt pplace of its in sorted array and all the smaller in left side and greater in right side. 
    arr[j] = pivot;
    pivot = temp;
    return j; // here we are returning j becaue if we don't return j then we can't have partition INdex.
}

void quickSort(vector<int> &arr, int low, int high){
if(low<=high){ //it  will check if array has not single value.
    int partitionIndex = doPartition(arr,low,high); //it will return the partiion Index so that smaller values less than the pivot will come lefyt side of pivot value and greater value will come right side of pivot value.
    quickSort(arr,low,partitionIndex-1); // recursion here. 
    quickSort(arr,partitionIndex+1,high);
}
}

int main(){
    int n,i;
    
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the value of arrays:";
    for(i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i+1<<"value: ";
        cin>>arr[i];
    }

    //calling the quickSort funciton by giving the arr, lowIndex and highIndex
    quickSort(arr,0,arr.size()-1);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;  // Indicate successful execution
}