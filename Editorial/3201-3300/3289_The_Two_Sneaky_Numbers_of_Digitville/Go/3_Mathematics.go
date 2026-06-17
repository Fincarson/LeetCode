func getSneakyNumbers(nums []int) []int {
	n := len(nums) - 2
	sum, squaredSum := 0.0, 0.0
	for _, x := range nums {
		sum += float64(x)
		squaredSum += float64(x * x)
	}
	sum2 := sum - float64(n*(n-1)/2)
	squaredSum2 := squaredSum - float64(n*(n-1)*(2*n-1)/6)
	x1 := (sum2 - math.Sqrt(2*squaredSum2-sum2*sum2)) / 2
	x2 := (sum2 + math.Sqrt(2*squaredSum2-sum2*sum2)) / 2
	return []int{int(x1), int(x2)}
}
