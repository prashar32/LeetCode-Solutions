class Solution {
public:
    bool checkIfPangram(string sentence) {
        for(char ch='a' ; ch<='z' ; ch++)
            if(sentence.find(ch)==string::npos)
                return false;
        return true;
    }
};