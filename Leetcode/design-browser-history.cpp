// problem link
// https://leetcode.com/problems/design-browser-history/description/

#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    int cur = 0;
    int sz = 0;
    vector<string> history;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        sz = 1;
    }
    
    void visit(string url) {
        cur += 1;
        if(cur < (int)history.size()) {
            history[cur] = url;
        } else {
            history.push_back(url);
        }
        sz = cur + 1;
    }
    
    string back(int steps) {
        cur = max(0, cur-steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur = min(sz-1, cur+steps);
        return history[cur];
    }
};