class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s)
        m = len(p)
        memo = [[-1 for i in range(m+1)] for j in range(n+1)]
        def solve(i,j):
            # base condition
            if i == 0:
                if j == 0 : return True
                else:
                    for temp in range(j):
                        if p[temp] != "*":
                            return False
                    return True
            elif j == 0:
                return False
            
            
            if memo[i][j] != -1:
                return memo[i][j]
            
            
            ans = False
            if s[i-1] == p[j-1] or p[j-1] == "?":
                ans = solve(i-1,j-1)
            
            elif p[j-1] == "*":
                ans = solve(i-1,j-1) or solve(i-1,j) or solve(i,j-1)
            else:
                return False
            memo[i][j] = ans
            return ans
        res = solve(n,m)
        # print(memo)
        return res
        
