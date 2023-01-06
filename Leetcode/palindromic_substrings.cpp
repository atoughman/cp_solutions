#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // odd
            int l = i;
            int r = i;
            // expand
            while (l >= 0 and r < s.size() and s[l] == s[r])
            {
                --l;
                ++r;
            }
            ++l;
            --r;
            ans += ceil((r - l + 1) / 2.0);

            // even
            l = i - 1;
            r = i;
            if (l >= 0 and s[l] == s[r])
            {
                // exapnd
                while (l >= 0 and r < s.size() and s[l] == s[r])
                {
                    --l;
                    ++r;
                }
                ++l;
                --r;
                ans += ceil((r - l + 1) / 2.0);
            }
            cout << endl;
        }
        return ans;
    }
};