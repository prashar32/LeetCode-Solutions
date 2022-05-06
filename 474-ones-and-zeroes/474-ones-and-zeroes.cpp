class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0 ; i<sz ; i++){
            int zero = count(strs[i].begin(), strs[i].end(), '0');
            int one = strs[i].size() - zero;
            for(int z=m ; z>=zero ; z--){
                for(int o=n ; o>=one ; o--){
                    dp[o][z] = max(dp[o][z], 1 + dp[o-one][z-zero]);
                }
            }
        }
        return dp[n][m];
    }
};