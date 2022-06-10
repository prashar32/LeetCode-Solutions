class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        vector<vector<int>>position(n+1, vector<int>(127, n));
        for(int i=n-2 ; i>=0 ; i--){
            position[i] = position[i+1];
            position[i]['~' - str[i+1]] = i+1;
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            int mini = n-1;
            for(int j=0 ; j<127 ; j++){
                if(j==('~' - str[i])){
                    mini = min(mini, position[i][j]-1);
                }
                else{
                    mini = min(mini, position[position[i][j]][j]-1);
                }
            }
            ans = max(ans, mini-i+1);
        }
        return ans;
    }
};