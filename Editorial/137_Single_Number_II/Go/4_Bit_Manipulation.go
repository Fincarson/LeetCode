func singleNumber(nums []int) int {
    // Loner
    var loner int = 0
    // Iterate over all bits
    for shift := 0; shift < 32; shift++ {
        var bit_sum int = 0
        // For this bit, iterate over all integers
        for _, num := range nums {
            // Compute the bit of num, and add it to bit_sum
            bit_sum += (num >> shift) & 1
        }
        // Compute the bit of loner and place it
        var loner_bit int = bit_sum % 3
        loner = loner | (loner_bit << shift)
    }
    // Do not mistaken sign bit for MSB.
    if loner >= (1 << 31) {
        loner = loner - (1 << 32)
    }
    return loner
}
