/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            ans = 0;
            int sz = que.size();
            for(int i=0 ; i<sz ; i++){
                auto x = que.front();
                ans+=(x->val);
                que.pop();
                if(x->left)que.push(x->left);
                if(x->right)que.push(x->right);
            }
        }
        return ans;
    }
};