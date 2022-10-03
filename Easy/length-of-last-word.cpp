/* Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only. */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        for(int i=s.size()-1; i>=0; --i){
            if(s[i]==' ' && count==0){
                continue;
            }
            else if(s[i]==' ' && count>0){
                return count;
            }
            else{
                count+=1;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<sol.lengthOfLastWord(str);
}