#A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

class Solution(object):
    def canMakeArithmeticProgression(self, arr):
        arr.sort()
        for i in range(1,len(arr)-1):
            if arr[i] - arr[i-1] != arr[i+1] - arr[i]:
                return False
        return True
