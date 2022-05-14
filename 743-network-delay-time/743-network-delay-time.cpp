class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1, INT_MAX);
        vector<pair<int,int>>adj[n+1];
        for(auto x : times){
            adj[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dis[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto [v,b] : adj[u]){
                if(dis[v] > dis[u] + b){
                    dis[v] = dis[u] + b;
                    pq.push({dis[v], v});
                }
            }
        }
        int answer = 0;
        for(int i=1 ; i<=n ; i++){
            if(dis[i]==INT_MAX)
                return -1;
            answer = max(answer, dis[i]);
        }
        return answer;
    }
};