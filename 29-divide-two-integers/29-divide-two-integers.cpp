class Solution {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        ll ans = (ll)dividend/(ll)divisor;
        if(ans < -1ll*(1ll<<31))ans = -1ll*(1ll<<31);
        if(ans >= 1ll*(1ll<<31))ans = 1ll*(1ll<<31)-1;
        return ans;
    }
};