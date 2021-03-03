/*This problem implements the Quick Sort algorihtm. 

Time: O(Nlog(N))
Space: O(Nlog(N))

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        quickSort(nums, 0, nums.size() - 1);
	    return nums;
    }
    
    void quickSort(vector<int> &nums, int startIdx, int endIdx) {
	
        if (startIdx >= endIdx) {
            return;
        }
        int pivot = startIdx, left = startIdx + 1, right = endIdx;
        while (right >= left) {
            if (nums.at(left) > nums.at(pivot) && nums.at(right) < nums.at(pivot)){
                swap(nums[left], nums[right]);
            }
            if (nums.at(left) <= nums.at(pivot)) {
                left++;
            }
            if (nums.at(right) >= nums.at(pivot)) {
                right--;
            }
        }
        swap(nums[pivot], nums[right]);
        
        bool isLeftSubarraySmaller = right - 1 - startIdx < endIdx - (right + 1);
        if (isLeftSubarraySmaller) {
            quickSort(nums, startIdx, right - 1);
            quickSort(nums, right + 1, endIdx);
        } else {
            quickSort(nums, right + 1, endIdx);
            quickSort(nums, startIdx, right - 1);
        }
    }
};
