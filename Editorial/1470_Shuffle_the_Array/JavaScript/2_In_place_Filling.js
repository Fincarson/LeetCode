var shuffle = function(nums, n) {
    // Store each y(i) with respective x(i).
    for (let i = n; i < 2 * n; ++i) {
        let secondNum = nums[i] << 10;
        nums[i - n] |= secondNum;
    }

    // '0000000000 1111111111' in decimal.
    let allOnes = Number(Math.pow(2, 10)) - 1;

    // We will start putting all numbers from the end, 
    // as they are empty places.
    for (let i = n - 1; i >= 0; --i) {
        // Fetch both the numbers from the current index.
        let secondNum = nums[i] >> 10;
        let firstNum = nums[i] & allOnes;
        nums[2 * i + 1] = secondNum;
        nums[2 * i] = firstNum;
    }
    return nums;
};
