// problem link
// https://leetcode.com/problems/course-schedule-iii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // if course deadline is early, process it first.
        sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int>&b) {
            if(a[1] == b[1]) {
                if(a[0] < b[0]) return true;
                return false;
            }
            if(a[1] < b[1]) return true;
            return false;
        });

        priority_queue<int> q;
        int time = 1;
        for(auto &x: courses) {
            if(time+x[0]-1 <= x[1]) {
                time += x[0];
                q.push(x[0]);
            } else {
                if(!q.empty() and x[0] < q.top()) {
                    time -= q.top();
                    q.pop();
                    q.push(x[0]);
                    time += x[0];
                }
            }
        }

        return q.size();
    }
};