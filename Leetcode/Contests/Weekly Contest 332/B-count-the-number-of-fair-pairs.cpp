#define ll long long

class Solution {
public:
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        sort(a.begin(), a.end());
        ll ans = 0;
        for(auto &x: a) {
            int low = lower - x;
            int high = upper - x;
            int in_range = (low <= x and x <= high);
            ll ld = upper_bound(a.begin(), a.end(), low-1) - a.begin();
            ll hd = upper_bound(a.begin(), a.end(), high) - a.begin() - (in_range);
            
            ans += hd-ld;
        }
        ans /= 2;
        return ans;
    }
};