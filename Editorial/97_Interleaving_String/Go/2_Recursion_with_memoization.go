// Golang does not have an inbuilt memoization function but it supports the usage of recursive functions and slice data structure which make it possible to manually implement memoization.
func isInterleave(s1 string, s2 string, s3 string) bool {
    if len(s1)+len(s2) != len(s3) {
        return false
    }
    memo := make([][]int, len(s1))
    for i := range memo {
        memo[i] = make([]int, len(s2))
        for j := range memo[i] {
            memo[i][j] = -1
        }
    }
    return is_Interleave(s1, 0, s2, 0, s3, 0, memo)
}

func is_Interleave(
    s1 string,
    i int,
    s2 string,
    j int,
    s3 string,
    k int,
    memo [][]int,
) bool {
    if i == len(s1) {
        return s2[j:] == s3[k:]
    }
    if j == len(s2) {
        return s1[i:] == s3[k:]
    }
    if memo[i][j] >= 0 {
        return memo[i][j] == 1
    }
    ans := false
    if (s3[k] == s1[i] && is_Interleave(s1, i+1, s2, j, s3, k+1, memo)) ||
        (s3[k] == s2[j] && is_Interleave(s1, i, s2, j+1, s3, k+1, memo)) {
        ans = true
    }
    if ans {
        memo[i][j] = 1
    } else {
        memo[i][j] = 0
    }
    return ans
}
