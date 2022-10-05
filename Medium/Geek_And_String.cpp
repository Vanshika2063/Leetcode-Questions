/*

Geek and Strings

Geek has a list Li containing (not necessarily distinct) N words and Q queries. Each query consists of a string x. For each query, find how many strings in the List Li has the string x as its prefix. 


Example 1:

Input: 
N = 5, Q = 5
li[] = {'abracadabra', 'geeksforgeeks', 
      'abracadabra', 'geeks', 'geeksthrill'}
query[] = {'abr', 'geeks', 'geeksforgeeks', 
         'ge', 'gar'}

Output: 2 3 1 3 0

Explaination: 
Query 1: The string 'abr' is prefix of 
two 'abracadabra'. 
Query 2: The string 'geeks' is prefix of three 
strings 'geeksforgeeks', 'geeks' and 'geeksthrill'. 
Query 3: The string 'geeksforgeeks' is prefix 
of itself present in li. 
Query 4: The string 'ge' also is prefix of three 
strings 'geeksforgeeeks', 'geeks', 'geeksthrill'. 
Query 5: The string 'gar' is not a prefix of any 
string in li.


*/

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        vector<int>ans;
        unordered_map<string,int>mp;
        for(int i=0;i<Q;i++)mp[query[i]]=1;
        for(int i=0;i<N;i++){
            string temp="";
            for(int j=0;j<li[i].size();j++){
                temp+=li[i][j];
                if(mp.find(temp)!=mp.end())++mp[temp];
            }
        }
        for(int i=0;i<Q;i++){
            ans.push_back(mp[query[i]]-1);
        }
        return ans;
    }
};