#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int freq[26] = {0};
        for (auto &x : s)
            freq[x - 'a']++;

        set<char> st;
        for (int i = 0; i < 26; i++)
            if (freq[i] != 1)
                freq[i] = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i] - 'a'])
                return i;
        }

        return -1;
    }
};