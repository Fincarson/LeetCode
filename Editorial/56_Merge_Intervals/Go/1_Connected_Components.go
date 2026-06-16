func overlap(a []int, b []int) bool {
    return a[0] <= b[1] && b[0] <= a[1]
}

func buildGraph(intervals [][]int) map[int][]int {
    graph := make(map[int][]int)
    for i, interval1 := range intervals {
        for j := i + 1; j < len(intervals); j++ {
            interval2 := intervals[j]
            if overlap(interval1, interval2) {
                graph[i] = append(graph[i], j)
                graph[j] = append(graph[j], i)
            }
        }
    }
    return graph
}

func mergeNodes(nodes []int, intervals [][]int) []int {
    minStart := intervals[nodes[0]][0]
    maxEnd := intervals[nodes[0]][1]
    for _, i := range nodes {
        minStart = int(math.Min(float64(minStart), float64(intervals[i][0])))
        maxEnd = int(math.Max(float64(maxEnd), float64(intervals[i][1])))
    }
    return []int{minStart, maxEnd}
}

func markComponentDFS(
    i int,
    compNumber int,
    visited map[int]bool,
    graph map[int][]int,
    nodesInComp map[int][]int,
) {
    stack := []int{i}
    for len(stack) != 0 {
        node := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if _, ok := visited[node]; !ok {
            visited[node] = true
            nodesInComp[compNumber] = append(nodesInComp[compNumber], node)
            for _, child := range graph[node] {
                stack = append(stack, child)
            }
        }
    }
}

func merge(intervals [][]int) [][]int {
    graph := buildGraph(intervals)
    nodesInComp := make(map[int][]int)
    visited := make(map[int]bool)
    compNumber := 0
    for i := range intervals {
        if _, ok := visited[i]; !ok {
            markComponentDFS(i, compNumber, visited, graph, nodesInComp)
            compNumber++
        }
    }
    merged := make([][]int, 0)
    for comp := 0; comp < compNumber; comp++ {
        merged = append(merged, mergeNodes(nodesInComp[comp], intervals))
    }
    return merged
}
