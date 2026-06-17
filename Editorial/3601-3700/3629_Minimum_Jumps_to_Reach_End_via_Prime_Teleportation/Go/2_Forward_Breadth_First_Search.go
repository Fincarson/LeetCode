const MX = 1000001

var factors [MX][]int

func init() {
	for i := 2; i < MX; i++ {
		if len(factors[i]) == 0 {
			for j := i; j < MX; j += i {
				factors[j] = append(factors[j], i)
			}
		}
	}
}

func minJumps(nums []int) int {
	n := len(nums)
	edges := make(map[int][]int)
	for i, a := range nums {
		for _, p := range factors[a] {
			edges[p] = append(edges[p], i)
		}
	}
	res := 0
	seen := make([]bool, n)
	seen[0] = true
	q := []int{0}
	for {
		var q2 []int
		for _, i := range q {
			if i == n-1 {
				return res
			}
			if i > 0 && !seen[i-1] {
				seen[i-1] = true
				q2 = append(q2, i-1)
			}
			if i < n-1 && !seen[i+1] {
				seen[i+1] = true
				q2 = append(q2, i+1)
			}
			if len(factors[nums[i]]) == 1 {
				p := nums[i]
				if list, ok := edges[p]; ok {
					for _, j := range list {
						if !seen[j] {
							seen[j] = true
							q2 = append(q2, j)
						}
					}
					delete(edges, p)
				}
			}
		}
		q = q2
		res++
	}
}
