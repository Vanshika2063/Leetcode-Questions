/* 
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

/*
Approach:
1. Find the first occurence of the target element using binary search
Once u find the element then move the high pointer to mid - 1 as we finding the first occurence there might be a chance that there
 is another occurence of the element before the current occurence

2. Find the last occurence of the target element using binary search
Once u find the element then move the low pointer to mid + 1 as we finding the last occurence there might be a chance that there
 is another occurence of the element after the current occurence
*/

// You can find this question on Leetcode:(34)

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int target, bool flag)
    {
        int low = 0;
        int high = nums.size()-1;
        
        int ansIndex = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target)
            {
                ansIndex = mid;
                if(flag == 0)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return ansIndex;
    }

    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = binarySearch(nums, target, 0); // flag = 0 for first occurence
        ans[1] = binarySearch(nums, target, 1); // flag = 1 for last occurence
        return ans;
    }
};