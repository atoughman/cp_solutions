// problem link
// https://leetcode.com/problems/add-binary/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = a.size();
        int m = b.size();
        string c = "";
        int i=0;
        int carry = 0;

        while(i < n or i < m) {
            int aa = i < n ? a[i]-'0' : 0;
            int bb = i < m ? b[i]-'0' : 0;
            int sum = aa + bb + carry;
            carry = sum>1;
            sum %= 2;
            if(sum == 0) c += '0';
            else c += '1';
            ++i;
        }

        if(carry) c += '1';
        reverse(c.begin(), c.end());

        return c;
    }
};