// problem link
// https://leetcode.com/problems/implement-stack-using-queues/description/

var MyStack = function() {
    this.q = []
};

/** 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    let len = this.q.length
    this.q.push(x)
    for(let i=0; i<len; i++) {
        this.q.push(this.q.shift())
    }
};

/**
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.q.shift();
};

/**
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.q[0];
};

/**
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.q.length === 0;
};