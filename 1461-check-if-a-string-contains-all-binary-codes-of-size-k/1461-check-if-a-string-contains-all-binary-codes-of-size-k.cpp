class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        string curr = "";
        set<string>se;
        for(int i=0 ; i<n ; i++){
            curr += s[i];
            if(curr.size() > k)curr.erase(curr.begin());
            if(curr.size() == k)se.insert(curr);
        }
        return (int)se.size() == (1<<k); 
    }
};