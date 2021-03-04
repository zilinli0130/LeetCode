/*
This problem implements the Two Pointer method to check whether the potential match strings inside
the dictionary is a sub string of the input string. We could skip some potential match strings which 
are smaller than the current result or with same length as the current result but lexicographical longer.


Time : O(M*N*K)
Space : O(1)
Where M is the length of inpt string, N is the length of dictionary and K is the average length of potential
match string inside the dictionary
*/

class Solution {
    
public:
    string findLongestWord(string s, vector<string>& d) {
        
        string result = "";
        
        for (int i=0;i < d.size(); i++){
            
            //Length of potential match string inside dictionary is smaller than the current result
            if (result.length() > d[i].length()) {
                continue;
            }
            
            //Length of potential match string inside dictionary is lexicographically longer than the current result
            if (result.length() == d[i].length() && result.compare(d[i]) < 0) {
                continue;
            }
            
            if (isSubstring(d[i],s)){
                result = d[i];
            }
        }
        return result;

      }
    
    bool isSubstring(string target,string s) {
        
        int idx1 = 0,idx2 = 0;
        while (idx1 < target.size() && idx2 < s.size()) {
            
            if (target[idx1] == s[idx2]){
                idx1++;
            }
            idx2++;
        }
        return idx1 == target.size(); //see if the index idx1 equals the lenghth of target string
    }
    
};
