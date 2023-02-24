// problem link
// https://leetcode.com/problems/number-of-1-bits/description/

var hammingWeight = function(n) {
    let ans = 0;
    while(n) {
        ans += n&1;
        n = Math.floor(n/2);
    }
    return ans;
};