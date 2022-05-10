class Solution {
public:
    
    vector<vector<int>>ans;
    
    void cal(int n, int k, vector<int>curr){
        if(n==0 && k==0){
            ans.push_back(curr);
            return;
        }
        if(n > 0){
            for(int val=curr.empty() ? 1 : curr.back()+1 ; val<=9 ; val++){
                if(n < val)break;
                curr.push_back(val);
                cal(n-val, k-1, curr);
                curr.pop_back();
            }            
        }
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        cal(n, k, curr);
        return ans;
    }
};