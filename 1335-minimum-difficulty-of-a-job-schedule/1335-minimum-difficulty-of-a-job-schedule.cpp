class Solution {
public:
    
    int minDifficulty(vector<int>& vec, int d) {
        int n = vec.size();
        if(d > n)return -1;
        vector<vector<int>>dp(d+1, vector<int>(n+1, 1e9));
        dp[0][0] = 0;
        for(int day=1 ; day<=d ; day++){
            for(int done=1 ; done<=n ; done++){
                dp[day][done] = vec[done-1] + dp[day-1][done-1];
                int maxi = vec[done-1];
                for(int j=done-1 ; j>day-1 ; j--){
                    maxi = max(maxi, vec[j-1]);
                    dp[day][done] = min(dp[day][done], maxi + dp[day-1][j-1]);
                }
            }
        }
        return dp[d][n];
    }
};