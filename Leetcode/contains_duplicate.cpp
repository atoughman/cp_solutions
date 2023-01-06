#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> freq;
        for (auto &x : nums)
        {
            freq[x]++;
            if (freq[x] > 1)
                return true;
        }
        return false;
    }
};