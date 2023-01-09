#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xorr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorr ^= nums[i] ^ (i + 1);
        }

        return xorr;
    }
};