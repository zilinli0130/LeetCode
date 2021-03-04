class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        //Padding on both sides
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        //Create a cache
        vector<vector<int>> cache(nums.size() + 2, vector<int>(nums.size() + 2, 0));
        
        for (int l = 1; l <= nums.size(); l++) {
            for (int i = 1; i <= nums.size() - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    cache[i][j] = max(cache[i][j], cache[i][k - 1] + cache[k + 1][j] 
                                      + nums[i - 1]*nums[k]*nums[j + 1]);
                }
            }
        }
       return cache[1][nums.size()]; 
    }
};
