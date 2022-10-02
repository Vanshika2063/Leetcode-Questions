class Solution:
    def plusOne(self, l: List[int]) -> List[int]:
        if l[-1]==9:
            s=''.join(map(str,l))
            a=str(int(s)+1)
            return list(map(int,a))
        else:
            l[-1]+=1
        return l
