/*
This problem implements the Two Pointer method. The max area is equal to the min length between these two pointers multiplying 
with the distance between those two pointers

Time : O(N)
Space : O(1)
Where N is the total number of elements inside the given array

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size() - 1, maxArea = 0;
        
        for (int i = 0; i < height.size(); i++) {
            
            if (height[left] < height[right]) {
                maxArea = max(maxArea, height[left] * (right - left));
                left++;
            } else {
                maxArea = max(maxArea, height[right] * (right - left));
                right--;
            }
        }
        return maxArea;
    }
};
