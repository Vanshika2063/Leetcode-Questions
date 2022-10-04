#link for question :-https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution:
    def findMin(self, nums: List[int]) -> int:
        n=len(nums)-1
        if(nums[0]<nums[n]):
            return nums[0]
        
        low=0
        high=n
        while(low<high):
            mid=(low+high)//2
            if mid==n:
                return nums[mid]
            if(nums[mid]<nums[mid-1] and nums[mid]<nums[mid+1]):
                return nums[mid]
            if(nums[mid]<nums[0]):
                high=mid-1
            else:
                low=mid+1
        return nums[high]
