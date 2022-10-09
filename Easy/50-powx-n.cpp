class Solution {
public:
    double myPow(double x, int n) {
        // For negative power (n<0)
        if(n<0) {
            if(n==-1)
                return 1/x;
            double ans = myPow(x, n/2);           // Recursive call
            if(n&1)
                return (1/x)*ans*ans;
            else
                return ans*ans;
        }
        
        // For positive power (n>0)
        if(n>0) {
            if(n==1)
                return x;
            double ans = myPow(x, n/2);           // Recursive call
            if(n&1)
                return x*ans*ans;
            else
                return ans*ans;
        }
        
        // For zero power (n==0)
        return 1;
    }
};