func getResults(queries [][]int) []bool {
	mx := 50000
	st := redblacktree.NewWithIntComparator()
	st.Put(0, nil)
	st.Put(mx, nil)

	for _, q := range queries {
		if q[0] == 1 {
			st.Put(q[1], nil)
		}
	}

	bt := make([]int, mx+1)
	update := func(x, v int) {
		for ; x < len(bt); x += x & -x {
			bt[x] = max(bt[x], v)
		}
	}

	query := func(x int) int {
		res := 0
		for ; x > 0; x -= x & -x {
			res = max(res, bt[x])
		}
		return res
	}

	pre := 0
	keys := st.Keys()
	for _, key := range keys {
		x := key.(int)
		if x == 0 {
			continue
		}
		update(x, x-pre)
		pre = x
	}

	ans := make([]bool, 0)
	for i := len(queries) - 1; i >= 0; i-- {
		q := queries[i]
		if q[0] == 2 {
			x := q[1]
			sz := q[2]

			floorNode, _ := st.Floor(x)
			preVal := 0
			if floorNode != nil {
				preVal = floorNode.Key.(int)
			}

			maxSpace := query(preVal)
			maxSpace = max(maxSpace, x-preVal)
			ans = append(ans, maxSpace >= sz)
		} else {
			x := q[1]
			lowerNode, _ := st.Floor(x - 1)
			preVal := 0
			if lowerNode != nil {
				preVal = lowerNode.Key.(int)
			}

			higherNode, _ := st.Ceiling(x + 1)
			nxt := mx
			if higherNode != nil {
				nxt = higherNode.Key.(int)
			}

			update(nxt, nxt-preVal)
			st.Remove(x)
		}
	}

	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	return ans
}
