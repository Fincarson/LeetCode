func minimumPairRemoval(nums []int) int {
	n := len(nums)
	next := make([]int, n)

	for i := 0; i < n; i++ {
		next[i] = i + 1
	}
	next[n-1] = -1
	count := 0
	for n-count > 1 {
		curr := 0
		target := 0
		targetAdjSum := nums[target] + nums[next[target]]
		isAscending := true

		for curr != -1 && next[curr] != -1 {
			if nums[curr] > nums[next[curr]] {
				isAscending = false
			}

			currAdjSum := nums[curr] + nums[next[curr]]
			if currAdjSum < targetAdjSum {
				target = curr
				targetAdjSum = currAdjSum
			}
			curr = next[curr]
		}

		if isAscending {
			break
		}

		count++
		next[target] = next[next[target]]
		nums[target] = targetAdjSum
	}

	return count
}
