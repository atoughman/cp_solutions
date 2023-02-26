// problem link
// https://leetcode.com/problems/longest-palindromic-substring/description/

let size = arr => {
    return arr[1] - arr[0] + 1;
}

var longestPalindrome = function(s) {
    let n = s.length;
    let range = [0,0]

    for(let i=0; i<n; i++) {
        for(let j=0; j<2; j++) { // for odd and even length
            let left = i-j;
            let right = i;
            while(left >=0 && right<n && s[left] === s[right]) {
                if(size(range) < size([left, right])) {
                    range = [left, right]
                }
                left -= 1;
                right += 1;
            }
        }
    }

    return s.slice(range[0], range[1]+1);
};