// Go
func climbStairs(n int) int {
    return climb_Stairs(0, n)
}

func climb_Stairs(i int, n int) int {
    if i > n {
        return 0
    }
    if i == n {
        return 1
    }
    return climb_Stairs(i+1, n) + climb_Stairs(i+2, n)
}
