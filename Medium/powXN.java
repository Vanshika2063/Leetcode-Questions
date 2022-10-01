class Solution {
    public double myPow(double x, int n) {
        
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(n<0){
            n = Math.abs(n);
            return 1/(x* myPow(x,n-1));
        }
        double partialAns = myPow(x, n/2);
        double ans = partialAns*partialAns;
        if(n%2 != 0)
            return ans*x;
        
        return ans;
    }
}