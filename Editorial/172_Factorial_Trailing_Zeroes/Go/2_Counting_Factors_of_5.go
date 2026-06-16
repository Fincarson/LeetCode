func trailingZeroes(n int) int {
    // Initialize zero count
    zeroCount := 0
    // Start from 5 until n with an increment of 5 at each iteration
    for i := 5; i <= n; i += 5 {
        // Set current factor as i at each iteration
        currentFactor := i
        // Until the current factor is divisible by 5, keep incrementing the zero count
        for currentFactor%5 == 0 {
            zeroCount++
            currentFactor /= 5
        }
    }

    return zeroCount
}
