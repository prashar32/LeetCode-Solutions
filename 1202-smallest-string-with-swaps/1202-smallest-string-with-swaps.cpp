class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int>adj[n+1];
        for(auto x : pairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n+1, false);
        string ans = s;
        for(int i=0 ; i<=n ; i++){
            if(!vis[i]){
                vector<int>pos;
                queue<int>que;
                que.push(i);
                vis[i] = true;
                while(que.size()){
                    int top = que.front();
                    que.pop();
                    pos.push_back(top);
                    for(auto x : adj[top]){
                        if(!vis[x]){
                            que.push(x);
                            vis[x] = true;
                        }
                    }
                }
                sort(pos.begin(), pos.end());
                string tmp = "";
                for(auto x : pos){
                    tmp += s[x];
                }
                sort(tmp.begin(), tmp.end());
                for(int j=0 ; j<pos.size() ; j++){
                    ans[pos[j]] = tmp[j];
                }
            }
        }
        return ans;
    }
};