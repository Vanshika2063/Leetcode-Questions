class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        memo = {}
        def recursive(n: int, k: int, target: int) -> int:
            if (target, n) in memo: 
                return memo[(target, n)]
            if target == 0 and n == 0:
                return 1
            elif target < 0 or n <= 0:
                return 0
            else:
                result = 0
                for face in range(1, k + 1):
                    result += recursive(n - 1, k, target - face)
                memo[(target, n)] = result
                return result 
        return recursive(n, k , target) % (10**9 + 7) 

#https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
