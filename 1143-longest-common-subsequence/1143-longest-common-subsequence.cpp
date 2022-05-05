class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                dp[i+1][j+1] = (text1[i]==text2[j]) ? 1 + dp[i][j] : max(dp[i][j+1], dp[i+1][j]); 
            }
        }
        return dp[n][m];
    }
};