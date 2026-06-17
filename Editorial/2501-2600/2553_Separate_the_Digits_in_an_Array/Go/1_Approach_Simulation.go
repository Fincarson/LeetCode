func separateDigits(nums []int) []int {
	res := []int{}
	for _, num := range nums {
		x := num
		tmp := []int{}
		for x > 0 {
			tmp = append(tmp, x%10)
			x /= 10
		}
		for i := len(tmp) - 1; i >= 0; i-- {
			res = append(res, tmp[i])
		}
	}
	return res
}
