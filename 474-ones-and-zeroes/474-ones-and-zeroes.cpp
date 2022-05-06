class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>>dp(sz+1, vector<vector<int>>(n+1, vector<int>(m+1, 0)));
        for(int i=0 ; i<sz ; i++){
            int zero = count(strs[i].begin(), strs[i].end(), '0');
            int one = count(strs[i].begin(), strs[i].end(), '1');
            for(int z=0 ; z<=m ; z++){
                for(int o=0 ; o<=n ; o++){
                    if(z<zero || o<one)
                        dp[i+1][o][z] = dp[i][o][z];
                    else 
                        dp[i+1][o][z] = max(dp[i][o][z], 1+dp[i][o-one][z-zero]);
                }
            }
        }
        int ans = 0;
        for(int z=0 ; z<=m ; z++){
            for(int o=0 ; o<=n ; o++){
                ans = max(ans, dp[sz][o][z]);
            }
        }
        return ans;
    }
};