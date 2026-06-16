var maximumTripletValue = function (nums) {
    let n = nums.length;
    let res = 0;
    for (let k = 2; k < n; k++) {
        let maxPrefix = nums[0];
        for (let j = 1; j < k; j++) {
            res = Math.max(res, (maxPrefix - nums[j]) * nums[k]);
            maxPrefix = Math.max(maxPrefix, nums[j]);
        }
    }
    return res;
};
