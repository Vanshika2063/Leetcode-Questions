class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2==0 && q%2==0) { 
            p/=2;
            q/=2;
        }
        
        int ans = 1 - (p%2) + (q%2);
        
        return ans;
    }
};