class Solution {
public:
    int maxProduct(vector<int>& nums) {
        bool gotNeg = false;
        int productNeg = -1;
        int product = 1;
        int ans = nums[0];
        for(auto x : nums){
            product *= x;
            ans = max(ans, product);
            if(product==0){
                gotNeg = false;
                productNeg = -1;
                product = 1;
            }
            else if(product < 0 && gotNeg){
                ans = max(ans, product/productNeg);
            }
            if(!gotNeg && product<0){
                gotNeg = true;
                productNeg = product;
            }
        }
        return ans;
    }
};