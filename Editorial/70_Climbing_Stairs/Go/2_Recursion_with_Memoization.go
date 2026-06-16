func climbStairs(n int) int {
    memo := make([]int, n+1)
    return climb_Stairs(0, n, memo)
}

func climb_Stairs(i int, n int, memo []int) int {
    if i > n {
        return 0
    }
    if i == n {
        return 1
    }
    if memo[i] > 0 {
        return memo[i]
    }
    memo[i] = climb_Stairs(i+1, n, memo) + climb_Stairs(i+2, n, memo)
    return memo[i]
}
