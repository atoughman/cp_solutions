#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, int> mp1;
        map<char, int> mp2;

        for (int i = 0; i < s.size(); i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }

        return mp1 == mp2;
    }
};