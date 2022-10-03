class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.find(nums[i]-1) != m.end())
            {
                m[nums[i]] = m[nums[i]-1] + 1;
            }
            else m[nums[i]] = 1;
            
            ans = max(ans, m[nums[i]]);
        }
        return ans;
    }
};
