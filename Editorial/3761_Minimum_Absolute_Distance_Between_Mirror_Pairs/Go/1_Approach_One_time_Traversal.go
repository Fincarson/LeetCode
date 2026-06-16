func minMirrorPairDistance(nums []int) int {
	reverseNum := func(x int) int {
		y := 0
		for x > 0 {
			y = y*10 + x%10
			x /= 10
		}
		return y
	}

	prev := make(map[int]int)
	n := len(nums)
	ans := n + 1

	for i, x := range nums {
		if idx, exists := prev[x]; exists {
			if i-idx < ans {
				ans = i - idx
			}
		}
		prev[reverseNum(x)] = i
	}

	if ans == n+1 {
		return -1
	}
	return ans
}
