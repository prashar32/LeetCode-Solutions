class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>cnt1(26, 0), cnt2(26, 0);
        for(auto x : word1)
            cnt1[x-'a'] += 1;
        for(auto x : word2)
            cnt2[x-'a'] += 1;
        for(int i=0 ; i<26 ; i++)
            if((cnt1[i] && !cnt2[i]) || (!cnt1[i] && cnt2[i]))
                return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};