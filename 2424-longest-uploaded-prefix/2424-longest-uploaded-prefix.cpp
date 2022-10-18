class LUPrefix {
public:
    int ans;
    vector<int>vec;
    int maxi;
    LUPrefix(int n) {
        maxi = n;
        vec.assign(n+1, 0);
        ans = 1;
        vec[0] = 1;
    }
    
    void upload(int video) {
        vec[video] = 1;
        while(ans <= maxi && vec[ans]==1)
            ans += 1;
    }
    
    int longest() {
        return ans-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */