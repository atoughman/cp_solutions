#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int rangeOR(int n)
	{
		double nn = n;
		int val = ceil(log2(nn+1));
		long long ans = (1LL << val) - 1;
		return ans;
	}
};