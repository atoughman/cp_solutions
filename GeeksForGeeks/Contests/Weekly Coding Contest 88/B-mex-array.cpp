#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<int> mexArray(int n,int a[])
	{
		int mn = 0;
		sort(a, a+n);
		int non = 0;
		for(int i=0; i<n; i++) {
		    if(a[i] == mn) ++mn;
		    if(a[i] != 0) ++non;
		}
		
		vector<int> ans;
		for(int i=0; i<non; i++) {
		    ans.push_back(0);
		}
		
		for(int i=non; i<n; i++) {
		    ans.push_back(mn);
		}
		
		return ans;
		
	}
};