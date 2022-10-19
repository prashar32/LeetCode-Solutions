class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto x : words)
            mp[x] += 1;
        vector<pair<int,string>>vec;
        for(auto [a,b] : mp){
            vec.push_back({-1*b, a});
        }
        sort(vec.begin(), vec.end());
        vector<string>ans;
        for(int i=0 ; i<k ; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};