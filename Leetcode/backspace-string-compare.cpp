// problem link
// https://leetcode.com/problems/backspace-string-compare/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void update_ind_after_applying_backspace(const string &a, int &ind) {
        int ct = 0;
        while(ind>=0) {
            if(a[ind] == '#') {
                --ind;
                ++ct;
            } else if(ct>0) {
                --ind;
                --ct;
            } else break;
        }
    }

    bool backspaceCompare(string s, string t) {
        int a = s.size() - 1;
        int b = t.size() - 1;

        while(a>=0 and b>=0) {
            update_ind_after_applying_backspace(s, a);
            update_ind_after_applying_backspace(t, b);

            if(a>=0 and b>=0) {
                if(s[a] != t[b]) {
                    return false;
                }
                --a;
                --b;
            }
        }
        
        update_ind_after_applying_backspace(s, a);
        update_ind_after_applying_backspace(t, b);

        if(a>=0 || b>=0) return false;
        return true;
    }
};