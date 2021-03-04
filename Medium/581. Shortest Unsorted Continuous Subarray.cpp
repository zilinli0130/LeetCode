/*
This problem implements the Two Pointer method. 
Steps:
1. Traverse the entire array from left side to compare the current value and current max value.
If the current max value is greater than the current value, it means that the current value is in 
its wrong position, we need to update the right pointer to this index

2. Traverse the entire array from right side to compare the current value and current min value.
If the current min value is smaller than the current value, it means that the current value is also in
its wrong position, we need to update the left pointer to this index

Time : O(N)
Space: O(1)
where N is the total elements inside the array
*/

#include <bits/stdc++.h>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        

        int left = nums.size(), right = 0;
        int currentMin = INT_MAX, currentMax = INT_MIN;
        
        
        //Find the right boundary
        for(int i = 0; i < nums.size(); i++) {
            currentMax = max(currentMax, nums[i]);
            if(nums[i] < currentMax) {right = i;}
        }
        
        //Find the left boundary
        for(int i = nums.size() - 1; i >= 0; i--) {
            currentMin = min(currentMin, nums[i]);
            if(nums[i] > currentMin) {left = i;}
        }
        
        return right - left < 0 ? 0 : right - left + 1; 
    }
};
