func solveQueries(nums []int, queries []int) []int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	pos := make(map[int]int)

	for i := -n; i < n; i++ {
		if i >= 0 {
			left[i] = pos[nums[i]]
		}
		pos[nums[(i+n)%n]] = i
	}

	pos = make(map[int]int)
	for i := 2*n - 1; i >= 0; i-- {
		if i < n {
			right[i] = pos[nums[i]]
		}
		pos[nums[i%n]] = i
	}

	for i := 0; i < len(queries); i++ {
		x := queries[i]
		if x-left[x] == n {
			queries[i] = -1
		} else {
			queries[i] = min(x-left[x], right[x]-x)
		}
	}

	return queries
}
