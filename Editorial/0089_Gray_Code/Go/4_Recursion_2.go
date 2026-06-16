var nextNum int

func grayCode(n int) []int {
    var result []int
    nextNum = 0
    grayCodeHelper(&result, n)
    return result
}

func grayCodeHelper(result *[]int, n int) {
    if n == 0 {
        *result = append(*result, nextNum)
        return
    }
    grayCodeHelper(result, n-1)
    // Flip the bit at (n - 1)th position from right
    nextNum = nextNum ^ (1 << (n - 1))
    grayCodeHelper(result, n-1)
}
