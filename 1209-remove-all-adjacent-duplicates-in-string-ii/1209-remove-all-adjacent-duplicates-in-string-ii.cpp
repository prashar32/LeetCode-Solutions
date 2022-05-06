class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>vec;
        vec.push_back({'#', 0});
        for(auto x : s){
            if(x == vec.back().first)
                vec.back().second += 1;
            else 
                vec.push_back({x, 1});
            if(vec.back().second == k)
                vec.pop_back();
        }
        s.clear();
        for(auto [character, count] : vec)
            s.append(count, character);
        return s;
    }
};