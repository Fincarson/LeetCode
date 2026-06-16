var getPermutation = function (n, k) {
    let factorials = new Array(n); // Factorial system bases
    let nums = ["1"]; // Numbers
    // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    // Generate nums 1, 2, ..., n
    factorials[0] = 1;
    for (let i = 1; i < n; ++i) {
        factorials[i] = factorials[i - 1] * i;
        nums.push((i + 1).toString());
    }
    // Fit k in the interval 0 ... (n! - 1)
    --k;
    // Compute the factorial representation of k
    let output = "";
    for (let i = n - 1; i > -1; --i) {
        let idx = Math.floor(k / factorials[i]);
        k -= idx * factorials[i];
        output += nums[idx];
        nums.splice(idx, 1);
    }
    return output;
};
