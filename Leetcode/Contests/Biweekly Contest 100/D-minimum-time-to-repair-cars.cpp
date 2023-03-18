#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, int>
#define ff first
#define ss second

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        int n = ranks.size();
        int a[n];
        int done = 0;
        ll ans = 0;
        int freq[103];
        memset(freq, 0, sizeof(freq));
        
        for(int i=0; i<n; i++) {
            a[i] = 1;
            if(freq[ranks[i]] == 0) pq.push({1LL*ranks[i]*a[i]*a[i], i});
            freq[ranks[i]]++;
        }
        
        while(true) {
            if(done >= cars) break;
            pl top = pq.top();
            pq.pop();
            // cout << top.ff << ' ' << top.ss << endl;
            int ind = top.ss;
            ans = top.ff;
            // cout << done << ' ' << pq.size() << ' ' << ind << ' ' << ans << endl;
            
            a[ind] += 1;
            pq.push({1LL*ranks[ind]*a[ind]*a[ind], ind});
            
            done += freq[ranks[ind]];
        }
        
        return ans;
        
    }
};