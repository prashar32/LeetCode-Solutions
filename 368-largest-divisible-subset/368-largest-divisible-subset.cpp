class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int n = nums.size();
        int cnt = 1;
        int idx = n-1;
        vector<int>temp(n, 0);
        vector<int>dp(n, 0);
        for(int i=n-1 ; i>=0 ; i--){
            dp[i] = 1;
            temp[i] = n;
            for(int j=i+1 ; j<n ; j++){
                if(nums[j]%nums[i] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    temp[i] = j;
                }
            }
            if(dp[i] > cnt){
                cnt = dp[i];
                idx = i;
            }
        }
        while(idx!=n){
            ans.push_back(nums[idx]);
            idx = temp[idx];
        }
        return ans;
    }
};