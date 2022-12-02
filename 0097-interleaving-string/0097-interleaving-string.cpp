class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int sz = s3.size();
        if(n+m != sz)
            return false;
        int cIdx = 0;
        queue<pair<int,int>>que;
        que.push({0,0});
        set<pair<int,int>>visited;
        visited.insert({0,0});
        while(cIdx < sz && que.size()){
            int o = que.size();
            bool got = false;
            while(o--){
                pair<int,int>pp = que.front();
                que.pop();
                if(pp.first < n && s1[pp.first] == s3[cIdx]){
                    got = true;
                    if(visited.find({pp.first+1, pp.second}) == visited.end())
                        que.push({pp.first+1, pp.second});
                    visited.insert({pp.first+1, pp.second});
                }
                if(pp.second < m && s2[pp.second] == s3[cIdx]){
                    got = true;
                    if(visited.find({pp.first, pp.second+1}) == visited.end())
                        que.push({pp.first, pp.second+1});
                    visited.insert({pp.first, pp.second+1});
                }
            }
            if(!got)
                return got;
            cIdx += 1;
        }
        return cIdx==sz;
        
    }
};