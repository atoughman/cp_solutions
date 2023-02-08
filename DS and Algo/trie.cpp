// problem link
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include<bits/stdc++.h>
using namespace std;

struct node {
    char ch;
    map<char, node*> mp;
    bool is_last;

    node(char x) {
        ch = x;
        is_last = false;
    }

    bool has(char x) {
        return mp.find(x) != mp.end();
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root = new node('#'); // doesn't matter as it is dummy
    }
    
    void insert(string word) {
        node* cur = root;
        for(auto x: word) {
            if(!cur->has(x)) cur->mp[x] = new node(x);
            cur = cur->mp[x];
        }
        cur->is_last = true;
    }

    node* match(string a) {
        node* cur = root;
        for(auto &x: a) {
            if(!cur->has(x)) return NULL;
            cur = cur->mp[x];
        }
        return cur;
    }
    
    bool search(string word) {
        node* cur = match(word);
        return cur == NULL ? false : cur->is_last;
    }
    
    bool startsWith(string prefix) {
        node* cur = match(prefix);
        return cur == NULL ? false : true;
    }
};