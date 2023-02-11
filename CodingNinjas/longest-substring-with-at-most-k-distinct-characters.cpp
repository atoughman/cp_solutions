// problem link
// https://www.codingninjas.com/codestudio/problems/distinct-characters_2221410?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    int freq[26] = {0};
    int uniq = 0;
    int l = 0;
    int ans = 0;
    int r = 0;
    int n = str.size();

    while(r<n) {
        int ind = str[r]-'a';
        if(freq[ind] == 0) ++uniq;
        freq[ind]++;
        
        while(uniq > k) {
            int y = str[l]-'a';
            if(freq[y] == 1) --uniq;
            freq[y]--;
            ++l;
        }

        ans = max(ans, r-l+1);

        ++r;
    }

    return ans;
}