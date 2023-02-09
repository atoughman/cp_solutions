#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void Answer() {
	int n;
	cin >> n;
	map<int,int> mp;
	int mx = 0;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		mp[a]++;
		mx = max(mx, a);
	}
	
	for(auto it=mp.rbegin(); it!=mp.rend(); it++) {
		if(it->second % 2 != 0) {
			cout << "Marichka" << endl;
			return;
		}
	}
	cout << "Zenyk" << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Answer();
	}
    return 0;
}