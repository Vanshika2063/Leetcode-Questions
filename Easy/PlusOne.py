class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        d=""
        for i in digits:
            d+=str(i)
        p=list(str(int(d)+1))
        return p
