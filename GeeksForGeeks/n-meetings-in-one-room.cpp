// problem link
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) v.push_back({end[i], start[i]});
        sort(v.begin(), v.end());
        
        int last = -1;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            if(v[i].second <= last) continue; 
            
            last = v[i].first;
            ++ans;
        }
        
        return ans;
    }
};