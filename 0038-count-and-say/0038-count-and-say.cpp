class Solution {
public:
    string countAndSay(int n) {
        string value = "1";
        for(int i=2 ; i<=n ; i++){
            string temp = "";
            int cnt = 1;
            char pre = value[0];
            for(int j=1 ; j<value.size() ; j++){
                if(value[j] == pre)
                    cnt += 1;
                else{
                    temp += to_string(cnt);
                    temp += pre;
                    pre = value[j];
                    cnt = 1;
                }
            }
            temp += ('0' + cnt);
            temp += pre;
            value = temp;
        }
        return value;
    }
};