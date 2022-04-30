class Solution {
public:
        map<string,vector<string>>adj;  
        map<string,double>mp;
        void dfs(string start, string end, bool& found, double& val, map<string,bool>& visited){
            visited[start] = true;
            if(found)return;
            for(auto x : adj[start]){
                if(!visited[x]){
                    val *= mp[start+"->"+x];
                    if(end==x){
                        found = true;
                        return;
                    }
                    dfs(x, end, found, val, visited);
                    if(found)return;
                    else 
                    val /= mp[start+"->"+x];
                }
            }
        }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        
        
        for(int i=0 ; i<eq.size() ; i++){
            mp[eq[i][0]+"->"+eq[i][1]] = values[i];
            mp[eq[i][1]+"->"+eq[i][0]] = 1.000/values[i];
            adj[eq[i][0]].push_back(eq[i][1]);
            adj[eq[i][1]].push_back(eq[i][0]);
        }
        vector<double>ans;
        for(int i=0 ; i<queries.size() ; i++){
            if(adj.find(queries[i][0])==adj.end() || adj.find(queries[i][1])==adj.end()){
                ans.push_back(-1);
                continue;
            }
            if(queries[i][0]==queries[i][1]){
                ans.push_back(1);
                continue;
            }
            double val = 1.000;
            map<string,bool>visited;
            bool found = false;
            dfs(queries[i][0], queries[i][1], found, val, visited);
            found ? ans.push_back(val) : ans.push_back(-1);
        }
        return ans;
    }
};