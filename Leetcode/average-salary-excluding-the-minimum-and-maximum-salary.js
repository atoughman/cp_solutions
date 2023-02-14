// problem link
// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

/**
 * @param {number[]} salary
 * @return {number}
 */
var average = function(salary) {
    let mn = Math.min(...salary);
    let mx = Math.max(...salary);
    let sum = salary.reduce((sum, current) => {
        const isMinMax = [mn, mx].includes(current);
        return sum + (isMinMax ? 0 : current);
    }, 0);
    return sum/(salary.length - 2);
};