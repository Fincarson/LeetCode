func twoEditWords(queries []string, dictionary []string) []string {
	var ans []string
	for _, query := range queries {
		for _, s := range dictionary {
			dis := 0
			for i := 0; i < len(query); i++ {
				if query[i] != s[i] {
					dis++
				}
			}
			if dis <= 2 {
				ans = append(ans, query)
				break
			}
		}
	}
	return ans
}
