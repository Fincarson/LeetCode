func minMoves(nums []int, limit int) int {
	n := len(nums)
	diff := make([]int, 2*limit+2)

	for i := 0; i < n/2; i++ {
		a := min(nums[i], nums[n-1-i])
		b := max(nums[i], nums[n-1-i])

		diff[2] += 2
		diff[a+1] -= 1
		diff[a+b] -= 1
		diff[a+b+1] += 1
		diff[b+limit+1] += 1
	}

	minOps := n
	currentOps := 0

	for c := 2; c <= 2*limit; c++ {
		currentOps += diff[c]
		minOps = min(minOps, currentOps)
	}

	return minOps
}
