func findXSum(nums []int, k int, x int) []int {
	n := len(nums)
	ans := make([]int, 0, n-k+1)

	for i := 0; i <= n-k; i++ {
		cnt := make(map[int]int)
		for j := i; j < i+k; j++ {
			cnt[nums[j]]++
		}

		type Pair struct {
			freq int
			num  int
		}
		freq := make([]Pair, 0, len(cnt))
		for num, count := range cnt {
			freq = append(freq, Pair{count, num})
		}
		sort.Slice(freq, func(i, j int) bool {
			if freq[i].freq != freq[j].freq {
				return freq[i].freq > freq[j].freq
			}
			return freq[i].num > freq[j].num
		})

		xsum := 0
		for j := 0; j < x && j < len(freq); j++ {
			xsum += freq[j].freq * freq[j].num
		}
		ans = append(ans, xsum)
	}

	return ans
}
