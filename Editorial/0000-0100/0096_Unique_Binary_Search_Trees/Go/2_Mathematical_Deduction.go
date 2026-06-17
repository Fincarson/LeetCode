func numTrees(n int) int {
    // Note: we should use int64 here instead of int, otherwise overflow
    var C int64 = 1
    for i := 0; i < n; i++ {
        C = C * 2 * int64(2*i+1) / int64(i+2)
    }
    return int(C)
}
