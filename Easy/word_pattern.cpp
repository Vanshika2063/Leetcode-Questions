// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:pattern = "abba", s = "dog cat cat dog"
 // true


/*
Logic && intution
It's pretty intutive since as we can clearly understand by reading this question that there should be one to one mapping first thing ,second think of the edge case then you will be able to get the logic.
For implementation part you can go through the above solution.

First create two unordered map for mapping char to string and string to char
create an answer vector to store
have an empty string st,traverse through it and if you you encounter empty space add it to answer vector
and keep string as it is. Lastly put all the string words in st and then in answer vector.
Here,comes the most important thing to understand
a) while traversing the answer vector check in the map if its found and if found then whether correctly mapped or not ,in case it is not correctly mapped then return false. (string to char)
b) similarly traverse the characters and check if found in the map ,if found but not mapped correctly then return false.
c) Exist the loop and map char to string and string to map****

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>umap1;
        unordered_map<string,char>umap2;
        vector<string>answer;
        string st=" ";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                answer.push_back(st);
                st=" ";
            }
            else{
                st.push_back(s[i]);
            }
        }
        answer.push_back(st);
        if(answer.size()!=pattern.length())
            return false;
        
        for(int i=0;i<answer.size();i++){
            if(umap2.find(answer[i])!=umap2.end()){
                if(umap2[answer[i]]!=pattern[i])
                    return false;
            }
            if(umap1.find(pattern[i])!=umap1.end()){
                if(umap1[pattern[i]]!=answer[i])
                    return false;
            }
            umap1[pattern[i]]=answer[i];
            umap2[answer[i]]=pattern[i];
        }
        return true;
    }
};

