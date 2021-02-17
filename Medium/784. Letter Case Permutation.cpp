#include <cstring>

/*
This problem implements the Depth First Search method. We could imagine this problem as BST traversal such that
the left subtree is upper case and right subtree is lower case or vice versa.

Time : O(2^N)
Space : O(2^M)
Where N is length of input string and M is number of letters inside the input string
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        vector<string> results; 
        dfs(S, results, 0);
        return results;  
    }
    
    void dfs(string &S, vector<string> &results, int idx) {
        
        if (idx == S.length()) {
            results.push_back(S);
            return;
        }
        
        //"Left Subtree" 
        dfs(S, results, idx + 1);
        
        //"Right Substree"
        if(!isdigit(S[idx])) {
            
            //Change the capital of letter
            if (isupper(S[idx])) {
                S[idx] = tolower(S[idx]);
            } else {
                S[idx] = toupper(S[idx]);
            }
            dfs(S, results, idx + 1);
        } 
    }
};