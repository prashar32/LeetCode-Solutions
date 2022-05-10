class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int MaximumSUM = accumulate(nums.begin(), nums.end(), 0);
        if(MaximumSUM&1)
            return false;
        int half = MaximumSUM/2;
        vector<bool>dp(half+1, false);
        dp[0] = true;
        for(auto x : nums){
            for(int i=half ; i>=0 ; i--){
                if(dp[i] && i+x <= half)
                    dp[i+x] = true;
            }
        }
        return dp[half];
    }
};