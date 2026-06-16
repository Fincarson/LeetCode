var minStartValue = function(nums) {
    // We use "total" for current step-by-step total, "minVal" for minimum 
    // step-by-step total among all sums. Since we always start with 
    // startValue = 0, therefore the initial current step-by-step total is 0, 
    // thus we set "total" and "minVal" be 0. 
    var minVal = 0;
    var total = 0;

    // Iterate over the array and get the minimum step-by-step total.
    for (var i = 0; i < nums.length; ++i) {
        total += nums[i];
        minVal = Math.min(minVal, total);
    }

    // We have to let the minimum step-by-step total equals to 1, 
    // by increasing the startValue from 0 to -minVal + 1, 
    // which is just the minimum startValue we want.
    return -minVal + 1;
};
