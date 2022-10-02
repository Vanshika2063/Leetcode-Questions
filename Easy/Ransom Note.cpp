#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         unordered_map<char,int>m1;
         unordered_map<char,int>m2;

        for(int i=0;i<ransomNote.size();i++)
            m1[ransomNote[i]]++;


        for(int i=0;i<magazine.size();i++)
            m2[magazine[i]]++;
      
        for(auto& it:m1){ 
             if(it.second>m2[it.first])
               return false;
            
        }

        return true ;

     }
};
int main()
{
    string ransomNote,magazine;
    cin>>ransomNote>>magazine;
    Solution result;
    if(result.canConstruct(ransomNote,magazine))
    cout<<"True"<<endl;
    else
    cout<<"false";
    return 0;
}
