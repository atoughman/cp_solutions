// problem link
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int connected_components = n;
        int extra_cables = 0;

        for (const auto& connection : connections) {
            if (uf.unite(connection[0], connection[1])) {
                connected_components--;
            } else {
                extra_cables++;
            }
        }

        if (connected_components - 1 > extra_cables) {
            return -1;
        }

        return connected_components - 1;
    }
};