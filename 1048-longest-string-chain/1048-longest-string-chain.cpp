class Solution {
public:
    static bool comp(string& a, string& b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        map<string,int>mp;
        for(int i=0 ; i<n ; i++){
            mp[words[i]] = i+1;
        }
        vector<int>ans(n+1, 1);
        for(int i=n-1 ; i>=0 ; i--){
            int sz = words[i].size();
            string tmp = "";
            for(int j=0 ; j<sz ; j++){
                if(mp[tmp + words[i].substr(j+1, sz-j-1)]){
                    int idx = mp[tmp + words[i].substr(j+1, sz-j-1)] - 1;
                    ans[idx] = max(ans[idx], ans[i]+1);
                }
                tmp += words[i][j];
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};