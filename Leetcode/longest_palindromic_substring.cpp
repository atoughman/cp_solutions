#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> pal_check(string &s, int l, int r)
    {
        pair<int, int> p = {-1, -1};
        while (l >= 0 and r < s.size() and s[l] == s[r])
        {
            p = {l, r};
            --l;
            ++r;
        }

        return p;
    }

    int get_l(pair<int, int> &p)
    {
        return p.second - p.first + 1;
    }

    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            // odd length palindrome
            pair<int, int> odd_r = pal_check(s, i, i);
            if (get_l(odd_r) > ans.size())
            {
                ans = s.substr(odd_r.first, get_l(odd_r));
            }

            // even length palindrome
            pair<int, int> even_r = pal_check(s, i, i + 1);
            if (even_r.first != -1 and get_l(even_r) > ans.size())
            {
                ans = s.substr(even_r.first, get_l(even_r));
            }
        }

        return ans;
    }
};