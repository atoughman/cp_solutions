#include <bits/stdc++.h> 
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

void Answer() {
	ll a,b;
	cin >> a >> b;
	
	ll n,m;
	ll ans = 0;
	cin >> n >> m;
	
	if(b*(m+1) > a*m) {
		ll x = n/(m+1);
		ans += a*x*m;
		n -= (x*(m+1));
	}
	
	ans += n*min(a,b);
	cout << ans << endl;
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
