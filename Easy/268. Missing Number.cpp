/*
This problem implements a hashset to keep track of current available numbers inside the nums array. 
We then loop through the numbers from [0, n] inclusiviely to check which number is missed.

Time : O(N)
Space : O(N)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int res = -1;
        unordered_set<int> hashset;
        for (int num : nums) {hashset.insert(num);}
        
        for (int idx = 0 ; idx < nums.size() + 1; idx++) {
            if (hashset.find(idx) == hashset.end()) {res = idx; break;}
        } 
        return res;
    }
};