#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
    int evenGrouping(int n,int a[])
    {
    	int ans = 0;
    	int prev[n];
    	int next[n];
    
    	for(int i=0; i<n; i++) {
    		next[i] = i+1;
    		prev[i] = i-1;
    	}
    
    	for(int i=0; i<n; i++) {
    		a[i] = floor(log2(a[i]));
    		// cout << a[i] << ' ';
    	}
    	// cout << endl;
    	int l=0;
    	int r=1;
    	int removed[n];
    	memset(removed, 0, sizeof(removed));
    
    	while(r<n) {
    		if(a[l] == a[r]) {
    			removed[l] = 1;
    			removed[r] = 1;
    			if(prev[l]>=0 ) next[prev[l]] = next[r];
    			if(next[r]<n) prev[next[r]] = prev[l];
    			
    			if(prev[l] == -1) {
    				l = next[r];
    				r = next[r]+1;
    			} else {
    				l = prev[l];
    				r = next[r];
    			}
    		} else {
    			l = next[l];
    			r = next[r];
    		}
    	}
    
    	for(int i=0; i<n; i++) {
    		if(removed[i] == 0) ++ans;
    	}
    
    	
    	return ans;
    }
};