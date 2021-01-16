/*This problem implements quick select algorithm with recursion approach

Time : Average in O(N), Worse in O(N^2)
Space : O(N)

*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int position = nums.size() - k, res = -1;
	    quickselectHelper(nums, 0, nums.size() - 1, position, res);
        return res;
    }
    
    void quickselectHelper(vector<int> &nums, int startIdx, int endIdx, int position, int &res) {
	  if (startIdx > endIdx) {
			return;
		}
		
		int pivot = startIdx, leftIdx = startIdx + 1, rightIdx = endIdx;
		while (leftIdx <= rightIdx) {
			
			if (nums[leftIdx] > nums[pivot] && nums[rightIdx] < nums[pivot]) {
				swap(nums[leftIdx], nums[rightIdx]);
			}
			if (nums[leftIdx] <= nums[pivot]) {
				leftIdx++;
			}
			if (nums[rightIdx] >= nums[pivot]) {
				rightIdx--;
			}
		}
		swap(nums[pivot], nums[rightIdx]);
		if (rightIdx == position) {
			res = nums[rightIdx];
            return;
		} else if (rightIdx < position) {
			quickselectHelper(nums, rightIdx + 1, endIdx, position, res);
		} else {
			quickselectHelper(nums, startIdx, rightIdx - 1, position, res);
		}
	}
};