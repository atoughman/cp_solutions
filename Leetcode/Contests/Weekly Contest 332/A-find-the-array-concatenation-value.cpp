class Solution {
public:
    int digit_length(int x) {
        int ct = 0;
        while(x) {
            x /=10;
            ++ct;
        }
        return ct;
    }
    long long findTheArrayConcVal(vector<int>& a) {
        int l = 0;
        int r = a.size() - 1;
        long long ans = 0;
        while(l<=r) {
            if(l != r) {
                ans += (1LL*a[l]*pow(10, digit_length(a[r]))) + a[r];
            } else {
                ans += a[l];
            }
            ++l;
            --r;
        }
        
        return ans;
    }
};