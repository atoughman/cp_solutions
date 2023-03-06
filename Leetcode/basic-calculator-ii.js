// problem link
// https://leetcode.com/problems/basic-calculator-ii/description/

const OPERATOR_MAP = new Map([
    ["+", 1],
    ["-", 1],
    ["*", 1],
    ["/", 1],
])

const handle = (a,b, op, st) => {
    switch(op) {
        case "+":
            st.push(a, b);
            break;
        case "-":
            st.push(a, -b);
            break;
        case "*":
            st.push(a*b)
            break;
        case "/":
            st.push(Math.trunc(a/b));
            break;
    }
}

var calculate = function(s) {
    let right = "";
    let op = "*";
    const st = [1]
    const n = s.length;

    for(let i=0; i<n; i++) {
        if(s[i] === " ") continue;

        // is number
        if(OPERATOR_MAP.has(s[i]) === false) {
            right += s[i];
            continue;
        }
        
        // is operator
        handle(st.pop(), Number(right), op, st)
        op = s[i];
        right = "";
    }
    handle(st.pop(), Number(right), op, st)

    let sum = st.reduce((acc, cur) => {
        return acc + cur;
    }, 0);

    return sum;
};