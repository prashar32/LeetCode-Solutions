/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int depth = 1;
        int pos = 0;
        queue<TreeNode*>que;
        que.push(original);
        while(!que.empty()){
            int n = que.size();
            depth+=1;
            pos = 0;
            for(int i=0 ; i<n ; i++){
                pos+=1;
                auto x = que.front();
                if(x==target){
                    while(que.size())que.pop();
                    break;
                }
                que.pop();
                if(x->left)que.push(x->left);
                if(x->right)que.push(x->right);
            }
        }
        int tdepth = 1;
        int tpos = 0;
        queue<TreeNode*>tque;
        tque.push(cloned);
        TreeNode* ans;
        while(!tque.empty()){
            int n = tque.size();
            tdepth+=1;
            tpos = 0;
            for(int i=0 ; i<n ; i++){
                tpos+=1;
                auto x = tque.front();
                if(tpos==pos && tdepth==depth){
                    ans = x;
                    while(tque.size())tque.pop();
                    break;
                }
                tque.pop();
                if(x->left)tque.push(x->left);
                if(x->right)tque.push(x->right);
            }
        }
        return ans;
    }
};