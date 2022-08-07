class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n+1, 0);
        for(int i=1 ; i<=n ; i++){
            dp[i] = dp[i-1] + books[i-1][1];
            int breadth = 0, height = 0;
            for(int j=i ; j>0 ; j--){
                breadth += books[j-1][0];
                height = max(height, books[j-1][1]);
                if(breadth > shelfWidth)
                    break;
                dp[i] = min(dp[i], dp[j-1]+height);
            }
        }
            
        return dp[n];
    }
};