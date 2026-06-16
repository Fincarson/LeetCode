var maximumGap = function (nums) {
    if (!nums || nums.length < 2) {
        return 0;
    }

    let maxVal = Math.max(...nums);
    let exp = 1;
    let radix = 10;
    let aux = new Array(nums.length);

    while (Math.floor(maxVal / exp) > 0) {
        let count = new Array(radix).fill(0);

        for (let num of nums) {
            count[Math.floor(num / exp) % 10]++;
        }

        for (let i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        for (let i = nums.length - 1; i >= 0; i--) {
            aux[--count[Math.floor(nums[i] / exp) % 10]] = nums[i];
        }

        for (let i = 0; i < nums.length; i++) nums[i] = aux[i];

        exp *= 10;
    }
    let maxGap = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        maxGap = Math.max(nums[i + 1] - nums[i], maxGap);
    }
    return maxGap;
};
