class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n, false);
        vector<int>col(n, -1);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                queue<int>que;
                que.push(i);
                vis[i] = true;
                col[i] = 1;
                while(que.size()){
                    int sz = que.size();
                    for(int j=0 ; j<sz ; j++){
                        int top = que.front();
                        que.pop();
                        for(auto x : graph[top]){
                            if(!vis[x]){
                                vis[x] = true;
                                col[x] = 1-col[top];   
                                que.push(x);
                            }
                            else{
                                if(col[x]==col[top]){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};