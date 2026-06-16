func getPermutation(n int, k int) string {
    factorials := make([]int, n) // Factorial system bases
    nums := make([]string, n)    // Numbers
    // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    // Generate nums 1, 2, ..., n
    factorials[0] = 1
    nums[0] = "1"
    for i := 1; i < n; i++ {
        factorials[i] = factorials[i-1] * i
        nums[i] = strconv.Itoa(i + 1)
    }
    // Fit k in the interval 0 ... (n! - 1)
    k = k - 1
    // Compute the factorial representation of k
    var output strings.Builder
    for i := n - 1; i > -1; i-- {
        idx := k / factorials[i]
        k -= idx * factorials[i]
        output.WriteString(nums[idx])
        nums = append(nums[:idx], nums[idx+1:]...)
    }
    return output.String()
}
