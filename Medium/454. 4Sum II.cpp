/*The problem implements the hash table method in which we loop through
list A and B to find out all the possible sum outputs. Next we need to 
loop through list C and D to find the (-1) * sum outputs of C and D. If 
this value is found inside the hash table, it means that we find a potential
combination. We then push the total number of combinations to the result

Time : O(N^2) where N is the length of one of the list by assuming all four lists have the same length
Space : O(N^2)


*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        int output = 0;
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                    hashmap[A[i] + B[j]]++; //accumulate the number of same ways
            }
        }
        
         for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                if (hashmap.find(-1 * (C[i] + D[j])) != hashmap.end()) {
                     output += hashmap[-1 * (C[i] + D[j])]; //add the satisfied number of same ways to the total results 
                }
            }
        }
        return output;
    }
};
