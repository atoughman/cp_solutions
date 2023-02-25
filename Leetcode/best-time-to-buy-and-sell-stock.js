// problem link
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

var maxProfit = function(prices) {
    let ans = 0;
    let mn = prices[0];

    for(let price of prices) {
        if(price < mn) mn = price;
        else ans = Math.max(ans, price-mn);
    }

    return ans;
};