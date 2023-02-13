// problem link
// https://leetcode.com/problems/k-closest-points-to-origin/description/

#include<bits/stdc++.h>
using namespace std;

//----------  max heap

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> q;
        vector<vector<int>> ans;
        
        for(int i=0; i<points.size(); i++) {
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            q.push({dis, i});

            if(q.size() > k) q.pop();
        }

        while(!q.empty()) {
            pair<int,int> top = q.top();
            q.pop();
            ans.push_back(points[top.second]);
        }

        return ans;
    }
};