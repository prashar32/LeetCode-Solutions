class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n, vector<int>(5, 0));
        for(int i=0 ; i<n ; i++){
            int lst = 0;
            for(int j=0 ; j<5 ; j++){
                if(!i){
                    dp[i][j] = 1;
                    continue;
                }
                lst += dp[i-1][j];
                dp[i][j] = lst;                
            }
        }
        return accumulate(dp[n-1].begin(), dp[n-1].end(), 0);
    }
};