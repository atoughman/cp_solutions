#include<bits/stdc++.h>
using namespace std;

int quick_select(int l, int r, vector<int> &nums, int k) {
    // cout << l << ' ' << r << endl;
    
    if(l == r) return nums[l];
    // search for pivot
    int mn = nums[l];
    int mx = nums[l];
    for(int i=l; i<=r; i++) {
        mn = min(mn, nums[i]);
        mx = max(mx, nums[i]);
    }

    if(mn == mx) return mn;  // optimization for range that is filled with same numbers

    int pivot = mn + (mx-mn)/2;

    int left = l;
    int right = r;
    while(true) {
        while(left+1 <= r and nums[left] <= pivot) ++left;
        while(right-1 >= l and nums[right] > pivot) --right;
        if(left>=right) break;
        swap(nums[left], nums[right]);
    }

    // for(auto x: nums) cout << x << ' ';
    // cout << endl;

    if(left <= k) return quick_select(left, r, nums, k);
    else return quick_select(l, left-1, nums, k);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];

    int k;
    cin >> k;
    // search element at kth position, if the elements are arranged in sorted position
    // however given array is unsorted array, and we are not required to sort whole array
    // as that would be n logn complexity. but
    // quick select gives linear time complexity on average. and n^2 in worst case.
    cout << quick_select(0, n-1, v, k) << endl;
}