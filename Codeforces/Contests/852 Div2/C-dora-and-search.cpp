#include <bits/stdc++.h> 
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

void Answer() {
	int n;
	cin >> n;
	int ar[n];
	for(int i=0; i<n; i++) {
		cin >> ar[i];
	}
	vector<int> mn;
	vector<int> mx;
	for(int i=1; i<n-1; i++) {
		if(ar[i-1] < ar[i] and ar[i] > ar[i+1]) {
			mx.push_back(i);
		}
		
		if(ar[i-1] > ar[i] and ar[i] < ar[i+1]) {
			mn.push_back(i);
		}
	}
	
	for(auto x: mn) {
		for(auto y: mx) {
			if(x < y) {
				int l1 = x-1;
				int r2 = y+1;
				if(ar[l1] < ar[y] and ar[r2] > ar[x]) {
					cout << l1+1 << ' ' << r2+1 << endl;
					return;
				}
			} else {
				int l2 = x+1;
				int r1 = y-1;
				if(ar[l2] < ar[y] and ar[r1] > ar[x]) {
					cout << r1+1 << ' ' << l2+1 << endl;
					return;
				}
			}
		}
	}
	
	cout << "-1" << endl;
}

int main() {
	FASTIO;
	int t;
	cin >> t;
	while(t--) {
		Answer();
	}
    return 0;
}
