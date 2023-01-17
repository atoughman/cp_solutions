// problem link
// https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvc vector<vector<char>>
#define pii pair<int,int>

class Solution {
public:
    bool solve(vvi &ver, vvi &hor, int (&mat)[3][3][9], stack<pii> &st, vvc &b) {
        if(st.empty()) return true;

        pii top = st.top();
        st.pop();

        int I = top.first;
        int J = top.second;

        for(int val = 0; val < 9; val++) {
            if(!ver[val][J] && !hor[I][val] && !mat[I/3][J/3][val]) {
                b[I][J] = val + '1';
                ver[val][J] = 1;
                hor[I][val] = 1;
                mat[I/3][J/3][val] = 1;

                if(!solve(ver, hor,mat, st, b)) {
                    b[I][J] = '.';
                    ver[val][J] = 0;
                    hor[I][val] = 0;
                    mat[I/3][J/3][val] = 0;
                } 
                else return true;
            }
        }

        st.push(top);
        return false;
    }

    void solveSudoku(vvc &board) {
        vvi ver(9, vi(9, 0));
        vvi hor(9, vi(9, 0));
        int mat[3][3][9];

        memset(mat, 0, sizeof(mat));
        

        stack<pii> st;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char ch = board[i][j];
                if(isdigit(ch)) {
                    int ind = ch - '1';
                    ver[ind][j] = 1;
                    hor[i][ind] = 1;
                    mat[i/3][j/3][ind] = 1;
                } else st.push({i,j});
            }
        }

        solve(ver, hor, mat, st, board);
    }
};