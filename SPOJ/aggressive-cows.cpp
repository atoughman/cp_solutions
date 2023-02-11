// problem link
// https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)

void Answer() {
    int n,c;
    cin >> n >> c;

    int ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);

    int l = ar[0];
    int r = ar[n-1];
    // cout << l << ' ' << r << endl;
    // guess
    while(l <= r) {
        int mid = l + (r-l)/2;

        int ct = 1;
        int low = 0;
        int high = 1;
        while(high < n) {
            if(ar[high] - ar[low] >= mid) {
                ++ct;
                low = high;
            }
            ++high;
        }

        if(ct < c) r = mid - 1;
        else l = mid + 1;
        // cout << l << ' ' << r << " : " << mid << ' ' << ct << endl;
    }

    cout << r << endl;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) Answer();

    return 0;
}