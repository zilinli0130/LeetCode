/*
This problem implements the dynamic programming technique. We could minimie this problem into 
what is the min number of coints to make up 0, 1, 2, ... all the way up to amount and come up
with the formula.

Time : O(M*N)
Space : O(N)
wheer N is the amount value and M is the coin options
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                
                if (coins[i] <= j) {
                    if (dp[j - coins[i]] != INT_MAX) {dp[j] = min(dp[j], 1 + dp[j - coins[i]]);}
                    else if (dp[j - coins[i]] == INT_MAX) {dp[j] = min(dp[j], dp[j - coins[i]]);}
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};