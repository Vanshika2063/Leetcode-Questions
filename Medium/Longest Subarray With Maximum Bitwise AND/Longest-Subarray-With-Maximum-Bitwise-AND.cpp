class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Intuition: Maximum AND is only possible when the subarray
        // contains only Maximum elements

        // Goal: Find longest subarray containing only maximum element

        int mx = *max_element(nums.begin(), nums.end()); // find the max element first
        int res=0, cur=0; // counter variables

        for(const int &num:nums){
            if(num==mx)cur++; // increase counter, if element is = max element
            else cur=0; // otherwise reset the counter
            res = max(res, cur); // maximize the result
        }
        return res;
    }
};