class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN and divisor==-1)
            return INT_MAX;
        else
            return (dividend/divisor);
        
    }
};