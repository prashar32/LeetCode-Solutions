class Solution {
public:
    int minDistance(string word1, string word2) {
        // changing word2 to word1
        swap(word1, word2);
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 5000));
        dp[0][0] = 0;       
        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; j<=m ; j++){
                if(i==0 && j==0)continue;
                else if(i==0){
                    dp[i][j] = j;
                    continue;
                }
                else if(j==0){
                    dp[i][j] = i;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + 1;
                bool have = false;
                for(int k=i-1 ; k>=0 ; k--){
                    if(word1[k]==word2[j-1])have = true;
                    have ? dp[i][j] = min(dp[i][j], dp[k][j-1] + i-k-1) : dp[i][j] = min(dp[i][j], dp[k][j-1] + 1 + i-k-1);
                }
            }
        }
        return dp[n][m];
    } 
};