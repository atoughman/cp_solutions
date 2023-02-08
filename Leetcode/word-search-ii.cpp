// problem link
// https://leetcode.com/problems/word-search-ii/description/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    map<char, Node*> mp;
    bool last;
    bool removed;

    Node(char x) {
        val = x;
        last = false;
        removed = false;
    }

    bool has(char x) {
        return mp.find(x) != mp.end();
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('#');
    }

    void add(string word) {
        Node* cur = root;
        for(auto &x: word) {
            if(!cur->has(x)) cur->mp[x] = new Node(x);
            cur = cur->mp[x];
        }
        cur->last = true;
    }

    bool remove_helper(string &word, Node* cur, int i) {
        if(i < word.size()) {
            bool can_remove = remove_helper(word, cur->mp[word[i]], i+1);
            if(can_remove) cur->mp.erase(cur->mp.find(word[i]));
        } else {
            cur->last = false;
        }

        if(cur->mp.empty()) {
            cur->removed = true;
            return true;
        }
        return false;
    }

    void remove(string word) {
        remove_helper(word, root, 0);
    }

};

class Solution {
public:
    int n,m;
    vector<vector<bool>> vis;
    vector<vector<char>> board;
    vector<string> ans;
    Trie* book;
    const int d4i[4] = {1, 0, -1, 0};
    const int d4j[4] = {0, 1, 0, -1};

    bool inside(int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m;
    }

    void dfs(int i, int j, Node* cur, string &so_far) {
        if(!inside(i, j) or vis[i][j] or !cur->has(board[i][j])) return;
        
        vis[i][j] = true;
        so_far += board[i][j];
        
        cur = cur->mp[board[i][j]];
        if(cur->last) {
            book->remove(so_far);
            ans.push_back(so_far);
        }

        for(int k=0; k<4; k++) {
            if(cur->removed) break;
            int I = i + d4i[k];
            int J = j + d4j[k];
            dfs(I, J, cur, so_far);
        }

        vis[i][j] = false;
        so_far.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        ans.clear();
        book = new Trie();
        for(auto &x: words) book->add(x);

        board = _board;
        n = board.size();
        m = board[0].size();
        vis.clear();
        vis.resize(n, vector<bool>(m, false));
        string so_far="";

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dfs(i, j, book->root, so_far);
            }
        }

        return ans;
    }
};