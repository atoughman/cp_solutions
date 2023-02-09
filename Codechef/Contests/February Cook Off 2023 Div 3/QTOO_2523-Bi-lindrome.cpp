#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void Answer() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> mp;
	for(auto x: s) {
		mp[x]++;
		if(mp[x] > 1) {
			cout << n-2 << endl;
			return;
		}
	}
	
	cout << "-1" << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Answer();
	}
    return 0;
}