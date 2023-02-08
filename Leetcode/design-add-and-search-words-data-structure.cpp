// problem link
// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

#include<bits/stdc++.h>
using namespace std;

struct node {
    char val;
    map<char, node*> mp;
    bool last;

    node(char x) {
        val = x;
        last = false;
    }

    bool has(char x) {
        return mp.find(x) != mp.end();
    }
};

class WordDictionary {
public:
    node* root;
    WordDictionary() {
        root = new node('#'); // dummy
    }
    
    void addWord(string word) {
        node* cur = root;
        for(auto &x: word) {
            if(!cur->has(x)) cur->mp[x] = new node(x);
            cur = cur->mp[x];
        }
        cur->last = true;
    }

    bool search_helper(string &word, node* cur, int i) {
        while(i<word.size()) {
            char x = word[i];
            if(x == '.') {
                for(auto &y: cur->mp) {
                    if(search_helper(word, y.second, i+1)) return true;
                }
                return false;
            } else {
                if(!cur->has(x)) return false;
                cur = cur->mp[x];
                ++i;
            }
        }
        return cur->last;
    }
    
    bool search(string word) {
        return search_helper(word, root, 0);
    }
};
