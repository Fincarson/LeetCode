var canDivideIntoSubsequences = function (nums, k) {
    let pre = nums[0],
        cnt = 0;
    for (let n of nums) {
        if (n === pre) {
            cnt++;
        } else {
            pre = n;
            cnt = 1;
        }
        if (cnt * k > nums.length) {
            return false;
        }
    }
    return true;
};
