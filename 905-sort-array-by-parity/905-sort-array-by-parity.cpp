class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]%2 == 0){
                swap(nums[i], nums[idx]);
                while(idx<i+1 && nums[idx]%2==0)idx += 1;
            }
        }
        return nums;
    }
};