// problem link
// https://leetcode.com/problems/maximum-product-subarray/description/

var maxProduct = function(nums) {
    let mx = 1;
    let mn = 1;
    let so_far = Number.MIN_SAFE_INTEGER;

    for(let num of nums) {
        let mx_pro = mx*num;
        let mn_pro = mn*num;

        mx = Math.max(num, mx_pro, mn_pro);
        mn = Math.min(num, mx_pro, mn_pro);

        so_far = Math.max(so_far, mx);
    }

    return so_far;
};