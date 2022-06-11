class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        bool got = false;
        int su = 0;
        int ans = 2*nums.size();
        map<int,int>mp;
        for(int i=0 ; i<nums.size() ; i++){
            su += nums[i];
            mp[su] = i+1;
        }
        if(mp[x]){
            got = true;
            ans = mp[x];
        }
        su = 0;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            su += nums[i];
            if(su==x){
                ans = min(ans, (int)nums.size()-i);
                got = true;
                continue;
            }
            if(mp[x-su] && mp[x-su]<=i){
                // cout<<i<<" "<<mp[x - su]<<"\n";
                ans = min(ans, mp[x-su] + (int)nums.size()-i);
                got = true;
                // break;
            }
        }
        if(!got)return -1;
        return ans;
    }
};