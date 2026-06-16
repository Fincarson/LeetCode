func divideString(s string, k int, fill byte) []string {
	var res []string // grouped string
	n := len(s)
	curr := 0 // starting index of each group
	// split string
	for curr < n {
		end := curr + k
		if end > n {
			end = n
		}
		res = append(res, s[curr:end])
		curr += k
	}
	// try to fill in the last group
	last := res[len(res)-1]
	if len(last) < k {
		last += strings.Repeat(string(fill), k-len(last))
		res[len(res)-1] = last
	}
	return res
}
