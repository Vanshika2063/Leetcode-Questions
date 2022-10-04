class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        diary = {}
        start = 0
        res = 0
        
        for i,c in enumerate(s):
            if c in diary:
                start = max(start, diary[c]+1)
            
            diary[c] = i
            res = max(res, (i-start) + 1)
            
        return res
