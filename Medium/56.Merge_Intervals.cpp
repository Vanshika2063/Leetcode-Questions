/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

1----3                      => 1----6
  2----6
        8----10             => 8----10  
                15----18    => 15----18

*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        for(int i=0; i<n; i++)
        {
            int s1 = intervals[i][0], e1 = intervals[i][1];
            for(int j=i+1; j<n; j++)
            {
                int s2 = intervals[j][0], e2 = intervals[j][1];
                // if overlap
                if(s2 <= e1){
                    e1 = max(e1, e2);
                    i = j;
                }
                // else break out of inner loop and add to ans
                else
                {
                    i=j-1;
                    break;
                }
            }
            ans.push_back({s1, e1});
        }   
        
        return ans;
    }
};