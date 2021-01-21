class Solution {
public:
/*This problem implements depth first search and backtrack approach
Time : O(N * 2^N)
Space: O(N)

*/
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subString;
        partitionHelper(s, 0, subString, result);
        return result;
    }

    void partitionHelper(string &s, int startIdx, vector<string>& subString, 
                         vector<vector<string>> &result) {
        
        if (startIdx > s.length() - 1) {
            result.push_back(subString);
        }
        
        for (int endIdx = startIdx; endIdx <= s.length() - 1; endIdx++) {
            
             if (isPalindrome(s, startIdx, endIdx)) {
                  subString.push_back(s.substr(startIdx, endIdx - startIdx + 1));
                  partitionHelper(s, endIdx + 1, subString, result);
                  subString.pop_back();
             }
        }
    }
    
    bool isPalindrome(string &s, int startIdx, int endIdx) {
        while (startIdx < endIdx) {
            if (s[startIdx++] != s[endIdx--]) {return false;}
        }
        return true;
    }
};
