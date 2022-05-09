class Solution {
public:
    vector<string>ans;
    void Push(vector<string>&vec, int i, string curr){
        if(i==vec.size()){
            ans.push_back(curr);
        }
        else{
            for(int j=0 ; j<vec[i].size() ; j++){
                curr += vec[i][j];
                Push(vec, i+1, curr);
                curr.pop_back();
            }
        }
    }
    
    
    vector<string> letterCombinations(string digits) {        
        if(digits.size() == 0)return ans;
        map<int,string>mp;
        char curr = 'a';
        for(int i=2 ; i<=6 ; i++){
            for(int j=0 ; j<3 ; j++){
                mp[i] += curr;
                curr += 1;
            }
        }
        mp[7] += "pqrs"; mp[8] += "tuv"; mp[9] += "wxyz";
        vector<string>vec;
        for(auto x : digits){
            vec.push_back(mp[x-'0']);
        }
        for(int j=0 ; j<vec[0].size() ; j++){
            string curr = "";
            curr += vec[0][j];
            Push(vec, 1, curr);
            curr.pop_back();
        }
        return ans;
    }
};