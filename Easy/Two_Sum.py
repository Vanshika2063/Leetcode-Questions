'''
Coded by TSG
'''

class Solution(object):
    def twoSum(self, nums, target):
        for idx , num in enumerate(nums):
            if (target - num) in nums:
                if nums.index(target - num) != idx:
                    return [idx , nums.index(target - num)]
