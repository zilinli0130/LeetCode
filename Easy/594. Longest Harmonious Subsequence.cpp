/* 
This problem implements the hash map and hash set method. We use hashmap to store all the number of elements inside the array. 
After then we go over the hash set to find the potential match.

Time: O(N)
Space: O(N)

*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int, int>hashmap;
        unordered_set<int> hashset;
        int res = 0;
        
        for (int num : nums) {
            hashmap[num]++;
            if (hashset.find(num) != hashset.end()) {
                continue;
            }
            hashset.insert(num);
        } 
        
        for(auto num : hashset) {
            
            int potentialMatch1 = num + 1, potentialMatch2 = num - 1;
            if (hashset.find(potentialMatch1) != hashset.end()) {
                res = max(res, hashmap[potentialMatch1] + hashmap[num]);
            }
            if (hashset.find(potentialMatch2) != hashset.end()) {
                res = max(res, hashmap[potentialMatch2] + hashmap[num]);
            }
        }
       return res; 
    }
};
