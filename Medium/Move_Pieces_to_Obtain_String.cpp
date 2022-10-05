/*
2337. Move Pieces to Obtain a String

You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

    The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
    The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.

Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

 

Example 1:

Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".
Since it is possible to get the string target from start, we return true.

Example 2:

Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.

Example 3:

Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.

 

Constraints:

    n == start.length == target.length
    1 <= n <= 10^5
    start and target consist of the characters 'L', 'R', and '_'.
*/

class Solution {
public:
    
bool canChange(string s, string t) {
        int n = s.size();
        if(n == 1)
        {
            if(s == t)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int cnt_sl = count(s.begin(), s.end(), 'L');
        int cnt_sr = count(s.begin(), s.end(), 'R');
        int cnt_tl = count(t.begin(), t.end(), 'L');
        int cnt_tr = count(t.begin(), t.end(), 'R');
        if(cnt_sl == cnt_tl and cnt_sr == cnt_tr)
        {
            vector<int>s_l;
            vector<int>s_r;
            for(int i = 0;i < n;i++)
            {
                if(s[i] == 'L')
                s_l.push_back(i);
                if(s[i] == 'R')
                s_r.push_back(i);
            }
            vector<int>t_l;
            vector<int>t_r;
            for(int i = 0;i < n;i++)
            {
                if(t[i] == 'L')
                t_l.push_back(i);
                if(t[i] == 'R')
                t_r.push_back(i);
            }
            vector<pair<int, int>>l;
            vector<pair<int, int>>r;
            for(int i = 0;i < s_l.size();i++)
            {
                l.push_back({s_l[i], t_l[i]});
            }
            for(int i = 0;i < s_r.size();i++)
            {
                r.push_back({s_r[i], t_r[i]});
            }
            sort(l.begin(), l.end());
            sort(r.begin(), r.end());
            for(int i = 0;i < l.size();i++)
            {
                if(l[i].first < l[i].second)
                {
                    return false;
                }
            }
            for(int i = 0;i < r.size();i++)
            {
                if(r[i].first > r[i].second)
                {
                    return false;
                }
            }
            int i = 0, j = 0;
            while(i < l.size() and j < r.size())
            {
                if(l[i].first < r[j].first and l[i].second < r[j].second)
                {
                    i++;
                }
                else if(l[i].first > r[j].first and l[i].second > r[j].second)
                {
                    j++;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};