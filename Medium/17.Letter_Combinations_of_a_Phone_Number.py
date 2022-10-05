class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits)==0:
            return []
        m={}
        k=["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        for i in range(2,10):
            m[str(i)]=list(k.pop(0))
        
        def trv(li,di,digits):
            p=m[di]
            ans=[]
            for i in li:
                for j in p:
                    ans.append(i+j)
            li=ans
            
            if len(digits)>0:
                p=digits[0]
                digits=digits[1:]
                return trv(li,p,digits)
            else:
                return ans
        li=m[digits[0]]
        digits=digits[1:]
        if len(digits)==0:
            return li
        p=digits[0]
        digits=digits[1:]
        
        return trv(li,p,digits)
