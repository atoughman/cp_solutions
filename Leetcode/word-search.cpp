#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    int d4x[4] = {0, 1, 0, -1};
    int d4y[4] = {1, 0, -1, 0};
    int vis[6][6];

    bool ok(int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j];
    }

    bool dfs(int i, int j, vector<vector<char>> &board, string &word, int ind)
    {
        if (board[i][j] == word[ind])
        {
            vis[i][j] = 1;

            if (ind + 1 == word.size())
                return true;

            for (int a = 0; a < 4; a++)
            {
                int I = i + d4x[a];
                int J = j + d4y[a];

                if (ok(I, J) and dfs(I, J, board, word, ind + 1))
                    return true;
            }

            vis[i][j] = 0;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(i, j, board, word, 0))
                    return true;
            }
        }

        return false;
    }
};