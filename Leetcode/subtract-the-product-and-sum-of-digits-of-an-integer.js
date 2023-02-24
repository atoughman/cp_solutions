// problem link
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description

var subtractProductAndSum = function(n) {
    let arr = (new String(n)).split('');
    
    let pro = arr.reduce((acc, cur) => {
        return acc * (+cur);
    }, 1);

    let sum = arr.reduce((acc, cur) => {
        return acc + (+cur);
    }, 0);
    
    return pro - sum;
};