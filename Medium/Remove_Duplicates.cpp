#include <iostream>
using namespace std;
void remove_duplicates(int*arr,int*n){
    int i=0;
    while(i<(*n)-1){
        if(arr[i]==arr[i+1]){
            for(int j=i+1;j<(*n)-1;j++){
                arr[j]=arr[j+1];
            }
            *n=*n-1;
        }
        else{
            i++;
        }
    }
}
void display(int*arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    remove_duplicates(arr,&n);
    
    display(arr,n);
    return 0;
}