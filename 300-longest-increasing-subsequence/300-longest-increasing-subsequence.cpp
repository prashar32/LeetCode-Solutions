class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int currLen = 0;
        for(auto x : nums){
            if(!currLen || nums[currLen-1] < x)nums[currLen++] = x;
            else{
                int idx = lower_bound(nums.begin(), nums.begin()+currLen, x) - nums.begin();
                nums[idx] = x;
            }
        }
        return currLen;
    }
};