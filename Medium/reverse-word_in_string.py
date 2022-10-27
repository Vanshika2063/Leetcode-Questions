
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split(" ")
        
        
        s = list(filter(lambda s: s != '', s))
        
        s = s[::-1]
        
        return ' '.join(s)