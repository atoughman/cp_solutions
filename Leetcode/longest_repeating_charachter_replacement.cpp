#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int most_freq_count(int ar[])
    {
        int mx = 0;
        for (int i = 0; i < 26; i++)
            mx = max(mx, ar[i]);
        return mx;
    }

    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0;
        int freq[26] = {0};
        int ans = 0;

        while (r < s.size())
        {
            freq[s[r] - 'A']++;

            // is window valid
            int len = r - l + 1;
            int char_replaced = len - most_freq_count(freq);

            // minimize till window becomes valid
            while (char_replaced > k)
            {
                freq[s[l] - 'A']--;
                ++l;
                len = r - l + 1;
                char_replaced = len - most_freq_count(freq);
            }
            ++r;
            ans = max(ans, len);
        }

        return ans;
    }
};