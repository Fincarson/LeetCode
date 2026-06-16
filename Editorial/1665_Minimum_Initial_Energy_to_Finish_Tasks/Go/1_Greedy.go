func minimumEffort(tasks [][]int) int {
	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][1]-tasks[i][0] < tasks[j][1]-tasks[j][0]
	})
	ans := 0
	for _, task := range tasks {
		if ans+task[0] > task[1] {
			ans = ans + task[0]
		} else {
			ans = task[1]
		}
	}
	return ans
}
