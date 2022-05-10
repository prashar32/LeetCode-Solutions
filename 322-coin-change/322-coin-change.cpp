class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=0 ; i<=amount ; i++){
            for(auto x : coins){
                if(dp[i]!=INT_MAX && i <= amount-x)
                    dp[i+x] = min(dp[i+x], dp[i] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};