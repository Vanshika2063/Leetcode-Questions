//Leetcode 152
//Question Link : https://leetcode.com/problems/maximum-product-subarray/



#include<bits/stdc++.h>
using namespace std;


int max_product(vector<int> arr)
{
    
    int num = arr.size();
    
    int max_till = arr[0]; // contains maximum value till visited element
    
    int imax = arr[0];
    int imin = arr[0];
    
    for(int i=1;i<num ;i++)
    {
        if(arr[i] < 0)
        {
            
            // when we multiply -ve element with bigger element then it become small and 
            // when we multiply smaller element with -ve number it becomes comparetively less small 
            swap(imax , imin);   
        }
        
        // imax will be current element or current element times previous imax element
        imax = max(arr[i] , arr[i]*imax);
        
        // similarly imin will be current element or current element times previous imin element
        
        imin = min(arr[i] ,  arr[i]*imin );
        
        
        max_till = max(max_till , imax);
        
        
    }
    
    return max_till;
}

int main()
{

vector<int> arr;

int num;
cin>>num;

for(int i=0;i<num;i++)
{
    int b;
    cin>>b;
    arr.push_back(b);
}


cout<<max_product(arr)<<endl;


    return 0;
}

