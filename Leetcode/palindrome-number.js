// problem link
// https://leetcode.com/problems/palindrome-number/description/

var isPalindrome = function(x) {
    let str = new String(x);
    return str == str.split("").reverse().join("")
};