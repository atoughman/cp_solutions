// problem link
// https://www.codechef.com/problems/HISC05

#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char source, char des, char helper) {
    if(n > 1) hanoi(n-1, source, helper, des);
    cout << "Disk " << n << " moved from " << source << " to " << des << endl;
    if(n > 1) hanoi(n-1, helper, des, source);
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 'A', 'C', 'B');
	return 0;
}
