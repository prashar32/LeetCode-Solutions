class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0, cnt2 = 0;
        set<char>se = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0 ; i<s.size()/2 ; i++){
            if(se.find(s[i]) != se.end())
                cnt1 += 1;
        }
        for(int i=s.size()/2 ; i<s.size() ; i++){
            if(se.find(s[i]) != se.end())
                cnt2 += 1;
        }
        return cnt1 == cnt2;
    }
};