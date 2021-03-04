/*
We could calclate the number of steps backward starting from Y:

if Y is odd and Y > X : Y++
if Y is even and Y > X: Y /= 2
if Y < X: Y++

Time : O(N)
Space : O(1)
*/
class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        if (X == Y) {return 0;}
        
        int res = 0;
        while (Y > X) {
            
            if (Y % 2 == 1) {
                Y++;
            } else {
                Y /= 2;
            }
            res++;
        }
    return res + X - Y;
    }
};




