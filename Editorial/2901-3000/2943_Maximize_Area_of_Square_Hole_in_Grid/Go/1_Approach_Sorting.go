func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {
	sort.Ints(hBars)
	sort.Ints(vBars)
	hmax, vmax := 1, 1
	hcur, vcur := 1, 1
	for i := 1; i < len(hBars); i++ {
		if hBars[i] == hBars[i-1]+1 {
			hcur++
		} else {
			hcur = 1
		}
		hmax = max(hmax, hcur)
	}
	for i := 1; i < len(vBars); i++ {
		if vBars[i] == vBars[i-1]+1 {
			vcur++
		} else {
			vcur = 1
		}
		vmax = max(vmax, vcur)
	}
	side := min(hmax, vmax) + 1
	return side * side
}
