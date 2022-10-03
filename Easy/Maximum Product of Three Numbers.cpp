// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 6
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:

// Input: nums = [-1,-2,-3]
// Output: -6
 

// Constraints:

// 3 <= nums.length <= 104
// -1000 <= nums[i] <= 1000

//solution

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        int i=0; int j=nums.size()-1; int ans=1;
        ans=nums[j]; j--;
            int a= (ans*nums[j]*nums[j-1]);
            int b= (ans*nums[i]*nums[i+1]);
        return max(a,b);
    }
};