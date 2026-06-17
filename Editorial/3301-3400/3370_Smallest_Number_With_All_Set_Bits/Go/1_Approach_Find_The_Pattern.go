func smallestNumber(n int) int {
	x := 1
	for x < n {
		x = x*2 + 1
	}
	return x
}
