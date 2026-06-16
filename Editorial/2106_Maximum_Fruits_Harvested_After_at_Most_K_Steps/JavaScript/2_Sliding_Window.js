var maxTotalFruits = function (fruits, startPos, k) {
    let left = 0;
    let right = 0;
    const n = fruits.length;
    let sum = 0;
    let ans = 0;
    // each time fix the right boundary of the window
    while (right < n) {
        sum += fruits[right][1];
        // move left boundary
        while (left <= right && step(fruits, startPos, left, right) > k) {
            sum -= fruits[left][1];
            left++;
        }
        ans = Math.max(ans, sum);
        right++;
    }
    return ans;
};

const step = (fruits, startPos, left, right) => {
    return (
        Math.min(
            Math.abs(startPos - fruits[right][0]),
            Math.abs(startPos - fruits[left][0]),
        ) +
        fruits[right][0] -
        fruits[left][0]
    );
};
