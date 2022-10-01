class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0, {});
        return res;
    }
    
    void solve(vector<int>& nums, int i, vector<int> cur) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        solve(nums, i+1, cur);
        cur.push_back(nums[i]);
        solve(nums, i+1, cur);
    }
};
