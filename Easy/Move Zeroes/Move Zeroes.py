class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        right=left=len(nums)
        for i in range(len(nums)):
            if nums[i]==0:
                right=left=i
                break
        while right<len(nums):
            if nums[right]!=0:
                nums[left],nums[right]=nums[right],nums[left]
                left+=1
            right+=1
        return nums
