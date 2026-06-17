func furthestDistanceFromOrigin(moves string) int {
	L, R, B := 0, 0, 0
	for _, c := range moves {
		if c == 'L' {
			L++
		} else if c == 'R' {
			R++
		} else {
			B++
		}
	}
	return int(math.Abs(float64(L-R))) + B
}
