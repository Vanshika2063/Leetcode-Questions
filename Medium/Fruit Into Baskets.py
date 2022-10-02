class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        right=0
        left=0
        counter={}
        max_len=0
        while right<len(fruits):
            if fruits[right] in counter:
                counter[fruits[right]]+=1
            else:
                counter[fruits[right]]=1
            if len(counter)>2:
                while len(counter)>2 :
                    if counter[fruits[left]]==1:
                        counter.pop(fruits[left])     
                    else:
                        counter[fruits[left]]-=1
                    left+=1
            elif len(counter)==2:
                max_len=max(max_len,right-left+1)
                while len(counter)==2 and right>len(fruits) :
                    if len(counter)==2:
                        max_len=max(max_len,right-left+1)
                        right+=1
                    if fruits[right] in counter:
                        counter[fruits[right]]+=1
                    else:
                        counter[fruits[right]]=1
            if len(counter)<2:
