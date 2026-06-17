func grayCode(n int) []int {
    var result []int
    grayCodeHelper(&result, n)
    return result
}

func grayCodeHelper(result *[]int, n int) {
    if n == 0 {
        *result = append(*result, 0)
        return
    }
    // derive the n bits sequence from the (n - 1) bits sequence.
    grayCodeHelper(result, n-1)
    currentSequenceLength := len(*result)
    // Set the bit at position n - 1 (0 indexed) and assign it to mask.
    mask := 1 << (n - 1)
    for i := currentSequenceLength - 1; i >= 0; i-- {
        // mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
        *result = append(*result, (*result)[i]|mask)
    }
    return
}
