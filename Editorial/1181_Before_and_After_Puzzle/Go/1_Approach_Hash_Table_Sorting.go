func beforeAndAfterPuzzles(phrases []string) []string {
	n := len(phrases)
	sp := [][]string{}
	for i := 0; i < n; i++ {
		s := strings.Split(phrases[i], " ")
		sp = append(sp, []string{s[0], s[len(s)-1]})
	}
	m := map[string]bool{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if sp[i][0] == sp[j][1] {
				m[phrases[j]+phrases[i][len(sp[i][0]):]] = true
			}
		}
	}
	ret := make([]string, 0)
	for k := range m {
		ret = append(ret, k)
	}
	sort.Strings(ret)
	return ret
}
