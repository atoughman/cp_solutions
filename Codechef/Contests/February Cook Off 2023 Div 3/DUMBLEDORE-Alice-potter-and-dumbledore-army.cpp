#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)

void Answer() {
	int n, m;
	cin >> n >> m;
	
	ll ans = 0;
	unordered_map<int,ll> ar;
	for(int i=0; i<m; i++) {
		ll a,b;
		cin >> a >> b;
		ar[a] += b;
		ans += ar[a];
		cout << ans << endl;
	}
}

int main() {
	FASTIO;
	Answer();
    return 0;
}