/* Leetcode Problem: 15. 3Sum
   Link: https://leetcode.com/problems/3sum/
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++)
        {            
            // for removing duplicates in the first element
            if(i > 0 && nums[i] == nums[i-1])continue;
                int a = i+1, b = n-1;
                while(a < b)
                {
                    int sum = nums[i]+nums[a]+nums[b];
                    // cout<<sum<<" ";
                    if(sum == 0)
                    {
                        ans.push_back({nums[i],nums[a],nums[b]});
                        // for removing duplicates in the second element
                        while(a < b && nums[a] == nums[a+1])
                            a++;
                        // for removing duplicates in the third element
                        while(a < b && nums[b] == nums[b-1])
                            b--;
                        a++;
                        b--;
                    }
                    else if(sum > 0)
                        b--;
                    else
                        a++;
                }
        }
        return ans;
    }
};