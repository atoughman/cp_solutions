// problem link
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function(low, high) {
    if(low % 2 === 0) low += 1;
    if(high % 2 === 0) high -= 1;
    if(high < low) return 0;
    return ((high-low)/2) + 1;
};