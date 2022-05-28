class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n+1, false);
        for(auto x : nums){
            vis[x] = true;
        }
        for(int i=0 ; i<=n ; i++){
            if(!vis[i])
                return i;
        }
        return n;
    }
};