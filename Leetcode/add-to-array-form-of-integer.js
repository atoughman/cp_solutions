// problem link
// https://leetcode.com/problems/add-to-array-form-of-integer/description/

// -----------------  FASTER

/**
 * @param {number[]} num
 * @param {number} k
 * @return {number[]}
 */
var addToArrayForm = function(num, k) {
    const rev = num.reverse();
    let ks = new String(k);
    ks = ks.split('');
    let krev = ks.reverse();
    let i = 0;
    let n = rev.length;
    let m = krev.length;
    let carry = 0;
    let ans = [];

    while(i<n || i<m) {
        let a = i<n ? rev[i] : 0;
        let b = i<m ? +krev[i] : 0; // converting char to int with + symbol
        let sum = a + b + carry;
        carry = sum > 9;
        sum = sum % 10;
        ans.push(sum);

        i += 1;
    }

    if(carry) ans.push(carry);

    return ans.reverse();
};

// ------------------- LAZY JS
/**
 * @param {number[]} num
 * @param {number} k
 * @return {number[]}
 */
var addToArrayForm = function(num, k) {
    let ans = BigInt(num.join('')) + BigInt(k);
    return String(ans).split('');
};