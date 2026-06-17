func closestTarget(words []string, target string, startIndex int) int {
	ans := len(words)
	n := len(words)

	for i, word := range words {
		if word == target {
			dist := abs(i - startIndex)
			ans = min(ans, min(dist, n-dist))
		}
	}

	if ans < n {
		return ans
	}
	return -1
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
