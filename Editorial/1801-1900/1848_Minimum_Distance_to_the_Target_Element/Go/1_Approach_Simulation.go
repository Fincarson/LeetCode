func getMinDistance(nums []int, target int, start int) int {
	res := len(nums)
	for i, num := range nums {
		if num == target {
			distance := int(math.Abs(float64(i - start)))
			res = min(res, distance)
		}
	}
	return res
}
