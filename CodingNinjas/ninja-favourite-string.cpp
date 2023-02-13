// problem link
// https://www.codingninjas.com/codestudio/problems/ninja-favourite-string_1460386?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int favString(string s, int k)
{
  	int freq[26] = { 0 };
	int n = s.size();

	int mxi = 0;
	for(auto &x: s) {
		freq[x-'a']++;
		if(freq[mxi] < freq[x-'a']) {
			mxi = x-'a';
		}
	}

	int mx = freq[mxi];
	int ct = 0;
	for(auto &x: freq) ct += mx == x;
	if((mx-1)*k+ct <= n) return 1;
	return 0;

}