78. Subsets
https://leetcode.com/problems/subsets/



class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        #recursion apporch
        def helper(p , up , ans):
            if up == []:
                p = p[:-1]
                ans.append(p.split(" "))
                return 
           
            
            helper(p+str(up[0])+" " , up[1:] , ans)
            helper(p , up[1:] , ans)
            return ans
            
        return helper("" , nums , [])
    
        
        #itrative apporch
        arr = [[]]
        for i in nums:
            for j in range(len(arr)):
                newItem = arr[j][:]
                newItem.append(i)
                arr.append(newItem)
        return arr
                
    
