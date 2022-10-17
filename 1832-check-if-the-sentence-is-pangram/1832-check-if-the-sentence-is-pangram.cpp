class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>have(26, false);
        for(auto x : sentence)
            have[x-'a'] = true;
        for(auto x : have)
            if(x == false)
                return false;
        return true;
    }
};