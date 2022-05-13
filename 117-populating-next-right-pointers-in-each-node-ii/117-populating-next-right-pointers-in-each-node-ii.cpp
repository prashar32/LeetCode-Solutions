/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>que;
        if(root)
            que.push(root);
        while(que.size()){
            int sz = que.size();
            for(int i=0 ; i<sz ; i++){
                Node* top = que.front();
                que.pop();
                if(i!=sz-1)
                    top->next = que.front();
                else
                    top->next = NULL;
                if(top->left)que.push(top->left);
                if(top->right)que.push(top->right);
            }
        }
        return root;
    }
};