/*
This problem implements the recursion method
Case0: "()" -> return 1
Case1: "()()...()" ->return score() + score() +...
Case2:"(((...)))" ->return 2 * score()...

Time : O(N)
Space : O(N)
*/
class Solution {
public:
    int scoreOfParentheses(string S) {
        return scoreHelper(S, 0, S.length() - 1);
    }
    
    int scoreHelper(string S, int left, int right) {
        
        //Base case "()"
        if (right - left == 1) {return 1;}
        
        int isBalance = 0;
        for (int i = left; i < right; i++) {
            
            if (S[i] == '(') {isBalance++;}
            if (S[i] == ')') {isBalance--;}
            if (isBalance == 0) {return scoreHelper(S, left, i) + scoreHelper(S, i + 1, right);}
        }
        return 2 * scoreHelper(S, left + 1, right - 1);
    }
};

