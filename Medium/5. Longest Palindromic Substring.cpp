class Solution {
public:
    //Approach 1: Depth First Search
    //Time : O(N^2)
    //Space : O(N^2)
    string longestPalindrome(string s) {
        
        if (s.length() <= 1) {return s;}
        vector<int> currentLongest = {0, 1}, temp;
        vector<bool> visited(s.length() - 1, false);
        dfs(s, currentLongest, visited, 0, temp);
        return s.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
        
    }
    
    void dfs(string s,  vector<int> &currentLongest, vector<bool> &visited, int count, vector<int> &temp) {
        if (count == s.length()) {return;}
        
        for (int i = 0; i < s.length(); i++) {
            if (!visited[i]) {
               if (temp.empty() || temp.back() - i == -1) {
                   visited[i] = true;
                   temp.push_back(i);
                   dfs(s, currentLongest, visited, count + 1, temp);
                   if (isPalidrome(temp, s)) {
                      currentLongest = currentLongest[1] - currentLongest[0] > temp.size()? 
                          currentLongest : vector<int>{temp[0], temp[temp.size() - 1] + 1};
                   }
                   temp.pop_back();
                   visited[i] = false;
               }
            }
        }
    }
    
    bool isPalidrome(vector<int> temp, string s) {
        int left = 0, right = temp.size() - 1;
        while (left <= right) {
            if (s[temp[left]] == s[temp[right]] ) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
    
/*Approach 2: Expand Around Center
    string longestPalindrome(string s) {
         vector<int> currentLongest = {0, 1};
        
        for (int i = 1; i < s.length(); i++) {
            vector<int> odd = getLongestPalidromeFrom(s, i - 1, i + 1);
            vector<int> even = getLongestPalidromeFrom(s, i -1, i);
            vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
            currentLongest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? currentLongest : longest;
        }
	 return s.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
    }
    
    vector<int> getLongestPalidromeFrom(string s, int L, int R) {
        while (L >= 0 && R < s.size()) {
            if (s[L] != s[R]) {
                break;
            }
            L--;
            R++;
        }
        return vector<int> {L + 1, R};
    }

*/
};
