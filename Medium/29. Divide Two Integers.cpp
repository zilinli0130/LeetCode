/*
This problem is all about math
log(a/b) = log(a) - log(b)
a/b = exp(log(a) - log(b))

Time : O(1)
Space : O(1)
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int sign = (dividend > 0) ^ (divisor > 0);
        
        /*XOR Truth Table
        //1  1 -> 0
        //1  0 -> 1
        //0  1 -> 1
        //0  0 -> 0
        */
        
        long length = abs(dividend);
        long interval = abs(divisor);
        long quotient = exp(log(length) - log(interval));
        
        quotient *= (sign == 1 ? -1 : 1);
        
        if(quotient > INT_MAX) {return INT_MAX;}
        if(quotient < INT_MIN) {return INT_MIN;}
        return quotient;
    }
};
