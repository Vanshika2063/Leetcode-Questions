class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        ls=[0]*len(arr)
        i=0
        k=0
        while i<len(arr):
            if arr[k]==0:
                ls[i]=0
                if i+1<len(arr):
                    ls[i+1]=0
                i=i+2
                
            else:
                ls[i]=arr[k]
                i=i+1
            k=k+1


        print(ls)
        for i in range(len(arr)):
            arr[i]=ls[i]
            
                
