class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>>vec(75, {0,0});
        for(int i=0 ; i<75 ; i++)
            vec[i].second = i;
        for(auto x : s)
            vec[x-'0'].first += 1;
        sort(vec.rbegin(), vec.rend());
        s = "";
        for(auto [a,b] : vec){
            s += string(a, b+'0');
        }
        return s;
    }
};