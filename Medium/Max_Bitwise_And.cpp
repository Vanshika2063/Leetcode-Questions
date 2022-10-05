/*
2419. Longest Subarray With Maximum Bitwise AND


You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

    In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.

Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.

 

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6
*/

class Solution {
public:
    
int longestSubarray(vector<int> &a)
{
	int n = a.size();
	int maxi = *max_element(a.begin(), a.end());
	int cnt = 0;
	int ans = -1;
	for(int i = 0;i < n;i++){
		if(a[i] == maxi){
			cnt = 0;
			while(i < n and a[i] == maxi){
				i++;
				cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	return ans;
}
};

