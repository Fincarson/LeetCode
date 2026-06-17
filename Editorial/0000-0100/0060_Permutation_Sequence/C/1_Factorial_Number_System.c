char *getPermutation(int n, int k) {
    int factorials[n];                            // Factorial system bases
    char *nums = malloc((n + 1) * sizeof(char));  // Numbers
    nums[n] = '\0';                               // Null terminate the string
    int i;
    factorials[0] = 1;  // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    nums[0] = '1';      // Generate numbers 1, 2, ..., n
    for (i = 1; i < n; ++i) {
        factorials[i] = factorials[i - 1] * i;
        nums[i] = (i + 1) + '0';
    }
    --k;  // Fit k in the interval 0 ... (n! - 1)
    // Compute the factorial representation of k
    char *result = malloc((n + 1) * sizeof(char));
    result[n] = '\0';  // Null terminate the string
    for (int j = n - 1, i = 0; j > -1; --j, i++) {
        int idx = k / factorials[j];
        k -= idx * factorials[j];
        result[i] = nums[idx];
        // Remove the element at index idx from nums
        memmove(&nums[idx], &nums[idx + 1], j - idx);
    }
    return result;
}
