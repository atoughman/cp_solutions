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


//             DP : ITERATIVE + 2-D MEMO

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        
        int mxr = 0;
        int mxc = 0;

        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
        }

        for(int i=0; i<n-1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1]) {
                mxr = i;
                mxc = i+1;
            }

        }

        for(int j=2; j<n; j++) {
            int r = 0;
            int c = j;
            while(c<n) {
                if(s[r] == s[c] and dp[r+1][c-1]) {
                    dp[r][c] = 1;
                } else dp[r][c] = 0;

                if(dp[r][c] and c-r+1 > mxc-mxr+1) {
                    mxr = r;
                    mxc = c;
                }

                ++r;
                ++c;
            }
        }

        return s.substr(mxr, mxc-mxr+1);
    }
};