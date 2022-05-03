class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(nums);
        sort(vec.begin(), vec.end());
        int i=0, j=n-1;
        while(i<n && nums[i]==vec[i])i++;
        while(j>i && nums[j]==vec[j])j--;
        return j-i+1;
    }
};