// problem link
// https://practice.geeksforgeeks.org/problems/90a81c305b1fe939b9230a67824749ceaa493eab/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
  public:
  vector<ll> countZero(int n, int k, vector<vector<int>>& arr){
      vector<ll> ans;
      ll r = n;
      ll c = n;
      ll rem_cells = r * c;
      
      unordered_set<int> rows, cols;
      
      for(int i=0; i<k; i++) {
          int R = arr[i][0];
          int C = arr[i][1];
          if(rows.find(R) == rows.end()) {
              rows.insert(R);
              --r;
              rem_cells -= c;
          }
          if(cols.find(C) == cols.end()) {
              cols.insert(C);
              --c;
              rem_cells -= r;
          }
          
          ans.push_back(rem_cells);
      }
      
      return ans;
  }
};