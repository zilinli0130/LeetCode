class Solution {
public:
/* The problem implements stack to keep track of the next minimum value (Greedy Algorithm)
Time : O(N)
Space: O(N)
*/
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack, result;
        int count = nums.size() - k;
        for(int num : nums) {
            while (!stack.empty() && num < stack.back() && count > 0) {
                stack.pop_back();
                count--;
            }
            stack.push_back(num);
        }
        
        if (stack.size() > k) {
            for (int i = 0; i < k; i++) {
                result.push_back(stack[i]);
            }
            return result;
        }
        return stack;
    }
    
    /*Greedy Approach
    //Time: O(N^2)
    //Space: O(N)
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> result;
        while (k > 0) {
            int startIdx, minValue = INT_MAX, minValueIdx;
            if (result.empty()) {
                startIdx = 0;
            } 
            
            for (int i = startIdx; i < nums.size(); i++) {
                if (nums[i] < minValue && i + k <= nums.size()) {
                    minValue = nums[i];
                    minValueIdx = i;
                }
            }
            result.push_back(minValue);
            startIdx = minValueIdx + 1;
            k--;
        }
        return result;
    }
    */
};
