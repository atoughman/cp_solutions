// problem link
// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int uniqueLetterString(string s) {
        ll ans = 0;
        ll so_far = 0;
        int left1[26];
        int left2[26];
        // left2 ... left1 ... cur  ( bcoz only last 2 occurances matter )
        memset(left1, 0, sizeof(left1)); 
        memset(left2, 0, sizeof(left2));

        for(int i=1; i<=s.size(); i++) {
            int x = s[i-1]-'A';
            so_far = so_far - (left1[x] - left2[x]) + (i - left1[x]);
            left2[x] = left1[x];
            left1[x] = i;
            ans += so_far;
        }

        return (int)ans;
    }
};