// problem link
// https://leetcode.com/problems/gas-station/description/

var canCompleteCircuit = function(gas, cost) {
    let start = -1;
    let dept = 0;
    let balance = 0;
    
    for(let i=0; i<gas.length; i++) {
        balance += gas[i]-cost[i];
        if(balance < 0) {
            dept += balance;
            balance = 0;
            start = -1;
        } else {
            if(start == -1) start = i;
        }
    }
    if(balance+dept >= 0) return start;
    return -1;
};