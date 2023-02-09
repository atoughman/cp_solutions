// problem link
// https://leetcode.com/problems/naming-a-company/description/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

//--------------- search and sort, hash ( Better )

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, bool> mp[26];
        for(auto &word: ideas) {
            string suf = word.substr(1, word.size() - 1);
            int i = word[0]-'a';
            mp[i][suf] = true;
        }

        ll ans = 0;

        for(int i=0; i<26; i++) {
            for(int j=i+1; j<26; j++) {
                ll common = 0;
                for(auto &x: mp[i]) {
                    if(mp[j].find(x.first) != mp[j].end()) ++common;
                }
                ans += (mp[i].size() - common) * (mp[j].size() - common) * 2;
            }
        }

        return ans;
    }
};


// -------------------- using trie

struct Node {
    map<char, Node*> mp;
    bool last;

    Node() {
        mp.clear();
        last = false;
    }

    bool has(char x) {
        return mp.find(x) != mp.end();
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void add(string word) {
        Node* cur = root;
        for(auto &x: word) {
            if(!cur->has(x)) cur->mp[x] = new Node();
            cur = cur->mp[x];
        }
        cur->last = true;
    }
};

#define ll long long

class Solution {
public:
    ll common_paths = 0;
    void calc(Node* a, Node* b) {
        if(a->last and b->last) {
            ++common_paths;
        }
        for(auto it=a->mp.begin(); it != a->mp.end(); it++) {
            for(auto jt=b->mp.begin(); jt != b->mp.end(); jt++) {
                if(it->first != jt->first) continue;
                calc(a->mp[it->first], b->mp[jt->first]);
            }
        }
    }

    ll distinctNames(vector<string>& ideas) {
        Trie* wordBook = new Trie();
        ll words[26]; // number of words with char a, char b etc. so size 26.
        memset(words, 0, sizeof(words));
        ll ans = 0;

        for(auto &word: ideas) {
            words[word[0]-'a']++;
            wordBook->add(word);
        }

        Node* r = wordBook->root;

        for(auto it=r->mp.begin(); it != r->mp.end(); it++) {
            for(auto jt=it; jt != r->mp.end(); jt++) {
                if(it==jt) continue;
                common_paths = 0;
                ll a_ct = words[it->first - 'a'];
                ll b_ct = words[jt->first - 'a'];

                calc(r->mp[it->first], r->mp[jt->first]);

                a_ct -= common_paths;
                b_ct -= common_paths;
                ans += a_ct * b_ct * 2;
            }
        }

        return ans;
    }
};