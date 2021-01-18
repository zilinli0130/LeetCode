/* This problem implements the hash map to keep track of the appeared number of 
elements inside the array. 

Time : O(N) where N is the total nubmer of elements inside an array
Space: O(M) where M is the total number of different elements inside an array

*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
       int result = 0;
       unordered_map<int, int> hashmap;
        
       for (int i = 0; i < nums.size(); i++) {
           
           int potentialMatch = k - nums[i];
           if (hashmap.find(potentialMatch) == hashmap.end()) {
              hashmap[nums[i]]++;
           } else {
               if (hashmap[potentialMatch] >= 1) {
                   hashmap[potentialMatch]--;
                   result += 1;
               } else {
                   hashmap[nums[i]]++;
                   continue;
               }
           }
       }
    return result;
    }
};