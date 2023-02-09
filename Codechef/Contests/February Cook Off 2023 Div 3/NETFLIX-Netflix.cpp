#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void Answer() {
	int a,b,c,x;
	cin >> a >> b >> c >> x;
	if(a+b >= x or b+c >=x or c+a >= x) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Answer();
	}
    return 0;
}