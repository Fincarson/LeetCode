func numSub(s string) int {
	const MODULO = 1000000007
	total := 0
	consecutive := 0
	for _, c := range s {
		if c == '0' {
			total += consecutive * (consecutive + 1) / 2
			total %= MODULO
			consecutive = 0
		} else {
			consecutive++
		}
	}
	total += consecutive * (consecutive + 1) / 2
	total %= MODULO
	return total
}
