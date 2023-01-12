#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int lv = matrix[0][0];
        int rv = matrix[n - 1][n - 1];

        while (lv < rv)
        {
            int mv = lv + (rv - lv) / 2;
            int ct = 0;
            for (int i = 0; i < n; i++)
            {
                auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mv);
                int dis = it - matrix[i].begin();
                ct += dis;
            }
            if (ct < k)
                lv = mv + 1;
            else
                rv = mv;
            // cannot return mv for ct == k, bcoz mv might not exist in matrix
            // we are playing guessing game, where mv is just guessed value.
            // with this approach, we are narrowing down to a value which exist in matrix
            // and satisfy the condition.
        }

        return lv;
    }
};