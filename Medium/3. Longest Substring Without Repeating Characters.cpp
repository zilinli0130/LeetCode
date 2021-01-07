#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//Time: O(N) | Space:O(M) where N is the length of arr, M is the size of hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.empty()) {
            return 0;
        }
        
        unordered_map<char, int> hashmap;
        vector<int> longest{0, 1}; //EndingIdx is exclusive
        int startIdx = 0;

        for (int i = 0; i < s.length(); i++) {

            if (hashmap.find(s[i]) != hashmap.end()) {
                
                //Update the startIdx of sliding window if element has been visited
                startIdx = max(startIdx, hashmap[s[i]] + 1);
            } 
            if (longest[1] - longest[0] < i + 1 - startIdx) {
                longest[1] = i + 1;
                longest[0] = startIdx;
            }
            hashmap[s[i]] = i;
        }
        return longest[1] - longest[0];
    }
};


