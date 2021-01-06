#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//Time: O(k*N) | Space:O(N) where N is the length of arr
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        //If the kth missed number is outside the range of arr, return the calculated kth missed number by formula
        int maxMiss = arr[arr.size() - 1] - arr.size();
        if (maxMiss < k) {
            return k - maxMiss + arr[arr.size() - 1];
        } else {

            //If the kth missed number is inside the range of arr, use hash table to solve this problem
            unordered_set<int> hashset;
            for (int i = 0; i < arr.size(); i++) {
                hashset.insert(arr[i]);
            }
            for (int i = 1; i < arr[arr.size() - 1] + 1; i++) {
                if (hashset.find(i) == hashset.end()) {
                    k--;
                }
                if (k == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};

