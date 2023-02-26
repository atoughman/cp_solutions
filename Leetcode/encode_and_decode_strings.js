let encode = arr => {
    return arr.reduce((acc, cur) => {
        return acc + cur.length + "#" + cur;
    }, "")
}

let decode = str => {
    let i = 0;
    let arr = []
    
    while(i<str.length) {
        // get word length
        let len = 0;
        while(str[i] !== '#') {
            len = len * 10 + (+str[i]);
            i += 1;
        }
        i += 1;
        
        // get word
        let word = ""
        while(len--) {
            word += str[i];
            i += 1;
        }
        arr.push(word);
    }

    return arr;
}


// testing code
let input = ['###','aman#123--','123#',':::']
let enc = encode(input);
let dec = decode(enc);

console.log(input)
console.log(enc)
console.log(dec);

import _ from 'lodash'
if(_.isEqual(dec, input)) {
    console.log("Correct ✅")
} else {
    console.log("Incorrect ❌")
}