// problem link
// https://leetcode.com/problems/string-compression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int l = 0, r = 0;

        while (r < n)
        {
            int freq = 1;
            while (r + freq < n and chars[r] == chars[r + freq])
                freq += 1;
            chars[l] = chars[r];
            if (freq != 1)
            {
                string s = to_string(freq);
                for (auto &x : s)
                {
                    l += 1;
                    chars[l] = x;
                }
            }
            r += freq;
            l += 1;
        }

        return l;
    }
};