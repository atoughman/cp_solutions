// problem link
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

var findMin = function(nums) {
    let left = 0;
    let right = nums.length - 1;
    if(nums[left] <= nums[right]) return nums[left];

    while(left <= right) {
        let mid = left + Math.floor((right - left)/2);
        if(nums[0] <= nums[mid]) left = mid + 1;
        else right = mid - 1;
    }

    return nums[left];
};