#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int len(pair<int, int> p)
    {
        return p.second - p.first + 1;
    }

    string minWindow(string s, string t)
    {
        int l = 0;
        int r = 0;
        map<char, int> mpt;
        map<char, int> mps;
        pair<int, int> ans = {-1, -1};

        for (auto &x : t)
            mpt[x]++;

        while (r < s.size())
        {
            mps[s[r]]++;

            // did we reach valid windows size ?
            bool valid = true;
            for (auto it : mpt)
            {
                if (mps[it.first] < it.second)
                {
                    valid = false;
                    break;
                }
            }

            while (valid)
            {
                if (ans.first == -1 or len(ans) > len({l, r}))
                    ans = {l, r};
                mps[s[l]]--;
                ++l;
                for (auto it : mpt)
                {
                    if (mps[it.first] < it.second)
                    {
                        valid = false;
                        break;
                    }
                }
            }
            ++r;
        }

        if (ans.first == -1)
            return "";
        else
            return s.substr(ans.first, len(ans));
    }
};