#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void Answer() {
	int n;
	cin >> n;
	int ct = 2;
	for(int i=0; i<n-1; i++) cout << ct++ << ' ';
	cout << 1 << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Answer();
	}
    return 0;
}