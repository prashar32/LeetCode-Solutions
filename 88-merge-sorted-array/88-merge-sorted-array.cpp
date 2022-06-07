class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = m-1, l2 = n-1;
        int idx = m+n-1;
        while(l1>=0 && l2>=0){
            nums1[idx--] = max(nums1[l1], nums2[l2]);
            nums1[l1] >= nums2[l2] ? l1 -= 1 : l2 -= 1;
        }
        while(l1>=0){
            nums1[idx--] = nums1[l1--];
        }
        while(l2>=0){
            nums1[idx--] = nums2[l2--];
        }
    }
};