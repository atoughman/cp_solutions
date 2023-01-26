// problem link
// https://www.codingninjas.com/codestudio/problems/employee-free-time_1171181

#include<bits/stdc++.h>
using namespace std;

vector<int> findFreeIntervals(vector<vector<int>> &schedules) {
	map<int,int> mp;
	for(auto &x: schedules) {
		for(int i=0; i<x.size(); i+=2) {
			int l = x[i];
			int r = x[i+1]+1;
			mp[l]++;
			mp[r]--;
		}
	}

	int start = -1;
	int ct = 0;
	vector<pair<int,int>> merged;
	for(auto &x: mp) {
		ct += x.second;
		if(start == -1) start = x.first;
		if(ct == 0) {
			merged.push_back({start, x.first});
			start = -1;
		}
	}

	vector<int> ans;
	for(int i=0; i<(int)merged.size(); i++) {
		if(merged[i].first != 0) {
			if(i == 0) ans.push_back(0);
			ans.push_back(merged[i].first - 1);
		}
		
		if(merged[i].second != 100000001) {
			ans.push_back(merged[i].second);
			if (i+1 == (int)merged.size()) ans.push_back(100000000);
		}
	}

	return ans;
}