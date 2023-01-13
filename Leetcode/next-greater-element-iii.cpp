// problem link
// https://leetcode.com/problems/next-greater-element-iii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        ll ans = 0;

        vector<int> v;
        int k = n;
        while (k)
        {
            v.push_back(k % 10);
            k /= 10;
        }
        reverse(v.begin(), v.end());
        bool possible = false;
        while (next_permutation(v.begin(), v.end()))
        {
            possible = true;
            for (auto &x : v)
                ans = ans * 10 + x;
            break;
        }

        ans = (int)ans;

        if (!possible or ans <= n)
            return -1;
        else
            return ans;
    }
};