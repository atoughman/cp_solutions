// problem link
// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll calc(vector<int>& time, ll t) {
        ll tot = 0;
        for(auto &x: time) tot += t/x;

        return tot;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1;
        ll mn = INT_MAX;
        for(auto &x: time) mn = min(mn, (ll)x);
        ll r = mn*totalTrips;

        while(l<=r) {
            ll mid = l + (r-l)/2;

            // validate
            ll trips = calc(time, mid);

            if(trips < totalTrips) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};