// problem link
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    
    public:

    int celebrity(vector<vector<int> >& M, int n) 
    {
        int l = 0;
        int r = n-1;
        
        while(l<r) {
            if(M[l][r] == 1) { // means l knows r, means l canot be celebrity
                ++l;
            } else { // means l doesn't know r, means r cannot be celebrity
                --r;
            }
        }
        
        // check if everybody knows l and l doesn't knows anybody
        for(int i=0; i<n; i++) {
            if(l!= i and (M[l][i] == 1 || M[i][l] == 0)) return -1;
        }
        
        return l;
    }
};