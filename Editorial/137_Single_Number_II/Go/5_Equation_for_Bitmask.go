func singleNumber(nums []int) int {
    // Initialize seenOnce and seenTwice to 0
    seenOnce, seenTwice := 0, 0

    // Iterate through nums
    for _, num := range nums {
        // Update using derived equations
        seenOnce = (seenOnce ^ num) & (^seenTwice)
        seenTwice = (seenTwice ^ num) & (^seenOnce)
    }

    // Return integer which appears exactly once
    return seenOnce
}
