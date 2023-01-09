#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx = 1;
        int mn = 1;

        int so_far = INT_MIN;
        for (auto &x : nums)
        {
            so_far = max(so_far, x);
        }

        for (auto &x : nums)
        {
            if (x == 0)
            {
                mx = 1;
                mn = 1;
            }
            int old_mx = mx;
            mx = max(x, max(mx * x, mn * x));
            mn = min(x, min(old_mx * x, mn * x));

            so_far = max(so_far, mx);
        }

        return so_far;
    }
};