#include<iostream>
#include<string>
#include<stack>
using namespace std  ;


class Solution {
public:
    bool isValid(string s) {
        
    stack<char> bass;
        int i=0;
        if(s.size()%2!=0)
            return false;
        while(i<s.size())
        {
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                bass.push(s[i]);
          else if(s[i]==']'||s[i]=='}'||s[i]==')')
          { 
              if(bass.empty())
                  return false;
              else if (s[i]==']'&&bass.top()!='[')
                  return false;
                else if (s[i]=='}'&&bass.top()!='{')
                  return false;
               else if (s[i]==')'&&bass.top()!='(')
                  return false;
              else 
                  bass.pop();
              }
            
            ++i;
        }
       
        

    if(bass.empty())
        return true;
        else
        return false;
    }
};

int main()
{

  Solution s1;
  string g("(");
  cout<<s1.isValid(g);

}











