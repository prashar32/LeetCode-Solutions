class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int su = 0;
        int n = nums.size();
        set<int>se;
        int l=0;
        for(int i=0 ; i<n ; i++){
            if(se.find(nums[i])!=se.end()){
                while(nums[l]!=nums[i]){
                    su -= nums[l];
                    se.erase(nums[l]);
                    l++;
                }
                su -= nums[l];
                se.erase(nums[l]);
                l++;
            }
            su += nums[i];
            se.insert(nums[i]);
            ans = max(ans, su);
        }
        return ans;
    }
};