#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int r = 0;
        int len = 0;
        int so_far = 0;
        map<char, int> mp;

        while (r < s.size())
        {
            if (mp[s[r]])
            {
                while (s[l] != s[r])
                {
                    mp[s[l]]--;
                    --len;
                    ++l;
                }
                mp[s[l]]--;
                --len;
                ++l;
            }
            mp[s[r]]++;
            ++len;
            ++r;
            so_far = max(so_far, len);
        }

        return so_far;
    }
};