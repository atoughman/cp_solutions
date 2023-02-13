// problem link
// https://leetcode.com/problems/maximum-frequency-stack/description/

#include<bits/stdc++.h>
using namespace std;

// using max heap { freq, time, element }

class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> mp;
    int time = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val], {time, val}});
        ++time;
    }
    
    int pop() {
        int top = pq.top().second.second;
        pq.pop();
        mp[top]--;
        return top;
    }
};

// input : 5, 4, 5, 3, 4, 4, 5
// using adjacency list kind of data structure, [freq : [elements]]
// 1 : [ 5, 4, 3 ] -> rightmost element is closest to top of stach
// 2 : [ 5, 4 ]
// 3 : [ 4, 5 ]

class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int, vector<int>> mp;
    int mx = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push_back(val);
        mx = max(mx, freq[val]);
    }
    
    int pop() {
        int val = mp[mx].back();
        mp[mx].pop_back();
        if(mp[mx].empty()) {
            mx--;
        }
        freq[val]--;

        return val;
    }
};

