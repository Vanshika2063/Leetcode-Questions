https://leetcode.com/problems/contains-duplicate/


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
		d = {}
        
        for i in nums:
            if i in d:
                return True
            d[i] = None
        
        return False
