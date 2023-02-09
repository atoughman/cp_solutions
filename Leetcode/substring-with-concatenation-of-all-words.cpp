// problem link
// 

#include<bits/stdc++.h>
using namespace std;

// short code : will probably work for interview

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        int ct = 0;
        int n = s.size();
        int w_len = words[0].size();
        int tot_words = words.size();

        if(n < w_len*tot_words) return ans;  // no possible index can be found

        map<string,int> freq;
        map<string,int> target;

        for(auto &x: words) {
            target[x] += 1;
        }

        int uniq = target.size();

        while(r<n) {
            string x = s.substr(r, w_len);
            freq[x] += 1;
            if(freq[x] == target[x]) ++ct;

            r += w_len;

            while(freq[x] > target[x]) {
                freq.clear();
                ++l;
                r = l;
                ct = 0;
            }

            if(ct == uniq) ans.push_back(l);
        }

        return ans;
    }
};


// ----------------- halka sa optimized , faster code, but lengthy

class Solution {
public:
    bool ok(string &s, map<string,int> &target_mp, const int &w_len, const int &uniq) {
        int l = 0;
        int r = 0;
        int ct = 0;
        int n = s.size();
        map<string,int> freq_mp;

        while(r<n) {
            string x = s.substr(r, w_len);
            freq_mp[x] += 1;

            if(freq_mp[x] == target_mp[x]) ++ct;
            if(freq_mp[x] > target_mp[x]) return false;
            
            if(ct == uniq) return true;
            r += w_len;
        }

        // will never reach here
        return false;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        int ct = 0;
        int n = s.size();
        int w_len = words[0].size();
        int tot_words = words.size();

        if(n < w_len*tot_words) return ans;  // no possible index can be found

        map<string,int> target_mp;
        int freq[26];
        int target[26];
        memset(freq, 0, sizeof(freq));
        memset(target, 0, sizeof(target));

        for(auto &x: words) {
            for(auto &y: x) target[y-'a'] += 1;
            target_mp[x] += 1;
        }

        int uniq = target_mp.size();

        for(int i=0; i<26; i++) if(freq[i] == target[i]) ct += 1;

        while(r < n) {
            int x = s[r]-'a';
            freq[x] += 1;
            
            if(freq[x] == target[x]) ++ct;

            while(freq[x] > target[x]) {
                int y = s[l]-'a';
                if(freq[y] == target[y]) --ct;
                freq[y] -= 1;
                l += 1;
            }

            if(ct == 26) { // possible substring found
                string sub = s.substr(l, r-l+1);
                if(ok(sub, target_mp, w_len, uniq)) ans.push_back(l);
            }

            r += 1;
        }

        return ans;
    }
};