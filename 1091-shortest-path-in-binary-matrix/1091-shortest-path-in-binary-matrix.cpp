class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])return -1;
        queue<pair<int,int>>que;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        que.push({0, 0});
        int ans = 1;
        while(!que.empty()){
            int sz = que.size();
            for(int i=0 ; i<sz ; i++){
                auto [x,y] = que.front();
                que.pop();  
                if(x==n-1 && y==n-1)return ans;
                for(int tx=-1 ; tx<=1 ; tx++){
                    for(int ty=-1 ; ty<=1 ; ty++){
                        if(x+tx>=0 && x+tx<n && y+ty>=0 && y+ty<n && !vis[x+tx][y+ty] && !grid[x+tx][y+ty]){
                            que.push({x+tx, y+ty});
                            vis[x+tx][y+ty] = true;
                        }
                    }
                }
            }
            ans += 1;
        }
        return -1;
    }
};