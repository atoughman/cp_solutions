// problem link
// https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

class Solution {
public:
    int n,m;
    int d4x[4] = {-1, 0, 1, 0};
    int d4y[4] = {0, 1, 0, -1};

    bool ok(int i, int j) {
        return i>=0 and j>=0 and i<n and j<m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pii> q;
        n = mat.size();
        m = mat[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            pii u = q.front();
            int i = u.first;
            int j = u.second;

            q.pop();

            for(int k=0; k<4; k++) {
                int I = i + d4x[k];
                int J = j + d4y[k];
                if(ok(I, J) and !vis[I][J]) {
                    mat[I][J] = mat[i][j] + 1;
                    vis[I][J] = true;
                    q.push({I, J});
                }
            }
        }

        return mat;
    }
};