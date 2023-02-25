// problem link
// https://leetcode.com/problems/3sum/description/

var threeSum = function(nums) {
    nums.sort((a,b) => {
        return a<b ? -1 : 1;
    });

    let n = nums.length;
    let ans = []

    for(let i=0; i<n; i++) {
        if(i !== 0 && nums[i] === nums[i-1]) continue;

        // 2 sum
        let target = -nums[i];
        let l = i+1;
        let r = n-1;
        while(l<r) {
            let sum = nums[l] + nums[r];
            if(sum === target) {
                ans.push([nums[i], nums[l], nums[r]]);
                l += 1;
                r -= 1;
                while(l<r && nums[l] === nums[l-1]) l += 1;
                while(l<r && nums[r] === nums[r+1]) r -= 1;
            } else if(sum < target) l += 1;
            else r -= 1;

        }
    }

    return ans;
};