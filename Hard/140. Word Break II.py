class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        out = []
        
        def check(wrd,s):
            n = len(s)
            for i in range(n+1):
                if s[:i] ==  wrd:
                    return [True,s[i:]]
            return [False,s]
        
        
        
        def recur(st,words):
            if st == "":
                out.append(words[1:])
                return 
            for wrd in wordDict:
                cond,val = check(wrd,st)
                if cond:
                    news = val
                    recur(news,words +" " + wrd)
        
        recur(s,"")
                
        return out
