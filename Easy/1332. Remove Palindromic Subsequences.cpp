/*
Case 0 : The string is empty, return 0
Case 1 : The string is a palindrome itself, return 1
Case 2 : Remove all the a's and then remove all the b's, return 2

Time : O(N)
Space : O(1)
*/

class Solution {
public:
    int removePalindromeSub(string s) {
        
        if(s.length() == 0) {return 0;}
        
        int result = 2;
        string reverse_s = s;
        reverse(reverse_s.begin(),reverse_s.end());
        if(s == reverse_s) {result = 1;}
        return result;
    }
};