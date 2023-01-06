#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string a;
        for (auto &ch : s)
        {
            char x = tolower(ch);
            if ((x >= 'a' and x <= 'z') or (x >= '0' and x <= '9'))
                a.push_back(x);
        }

        int l = 0;
        int r = a.size() - 1;
        while (l < r)
        {
            if (a[l] != a[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};