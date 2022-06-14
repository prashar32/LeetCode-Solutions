class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>lcs(2, vector<int>(m+1, 0));
        int curr = 1;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(word1[i-1]==word2[j-1])lcs[curr][j] = lcs[curr^1][j-1] + 1;
                else lcs[curr][j] = max(lcs[curr^1][j], lcs[curr][j-1]);
            }
            curr ^= 1;
        }
        return n+m-2*lcs[curr^1][m];
    }
};