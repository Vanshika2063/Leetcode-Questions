
#include <iostream>
#include <algorithm>
using namespace std;

bool containDuplicates(int arr[],int n){
    sort(arr,arr+n);
    /*sort function is implemented using quick sort*/
    /*sorting of the array using an inbult function in C++ algorithim header file*/
    int i=0;
    while(i<n-1){/*
    Treversed over each element of array in O(n) time.
        /*after sorting the array if the adjacent elements are similar then duplicates exist*/
        if(arr[i]==arr[i+1]){
            return true;
            
        }
        i++;
    }
    return false;
    
}
int main()
{
    int n,i=0;
    cin>>n;
    int*arr=new int[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if(containDuplicates(arr,n)){
        return true;
    }
    else{
        return false;
    }
    
    
    
    
    
    
    

    return 0;
}