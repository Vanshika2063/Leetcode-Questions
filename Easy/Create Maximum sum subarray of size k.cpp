#include <iostream>
using namespace std;
int maxsumsubarr(int arr[],int n,int k){
    int i=0,j=0,sum=0,maxi=0;
    while(j<n){
        sum+=arr[j];
        if(j-i+1<k)
        j++;
        else if(j-i+1==k){
            maxi=max(maxi,sum);
            sum=sum-arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}
int main() {
int arr[]={1,5,8,6,2,3};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<maxsumsubarr(arr,n,3);
	return 0;
}
