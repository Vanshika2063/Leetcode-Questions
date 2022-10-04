class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[i] = nums[i];
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back(m[nums[i]]);
        }
        return ans;
    }
};
