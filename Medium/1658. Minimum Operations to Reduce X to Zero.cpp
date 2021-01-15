/*This problem implements the sliding window method. Since we are going to fin the min numbers of element
whose sum is equal to x, this problem can be transferred into finding the subarray with max length whose element
sum is equal to total sum - x. We can apply the sliding window to find the max length subarray.

Time : O(N)
Space : O(1)

*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int left = 0, right = 0, res = 0, runningSum = 0, totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        
        int inverseSum = totalSum - x;
        if (inverseSum == 0) {return nums.size();}
        while (left < nums.size() && right < nums.size()) {
            
            if (runningSum < inverseSum) {
                runningSum += nums[right];
                right++;
            } else if (runningSum > inverseSum) {
                runningSum -= nums[left];
                left++;
            } else {
                res = max(res, right - left);
                runningSum -= nums[left];
                left++;
            }
        }
        
        if (runningSum == inverseSum) {
            res = max(res, right - left);
        }
        
        return res != 0 ? nums.size() - res : -1;
    }
};