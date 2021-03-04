/*
This problem implements the Depth First Search method to find all the permutations. We use a boolean array to keep track of
whether the current element is visited or not.

Time : O(N*N!), N! of leaves and N of depth for the recursion call tree
SPace : O(N*N!), store the resultant permutation array
where N is the length of nums
*/
class Solution {
private:
    vector<int> permutation;
    vector<vector<int>> results; 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<bool> visited(nums.size(), false);
        dfs(nums, visited, 0);
        return results;
    }
    
    void dfs(vector<int> &nums, vector<bool> &visited, int idx) {
        
        if (idx == nums.size()) {results.push_back(permutation); return;}
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (!visited[i]) {
                visited[i] = true;
                permutation.push_back(nums[i]);
                dfs(nums, visited, idx + 1);
                permutation.pop_back();
                visited[i] = false;
            }
        }
        return;
    }
};
