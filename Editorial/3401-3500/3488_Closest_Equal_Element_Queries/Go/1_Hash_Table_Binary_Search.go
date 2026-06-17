func solveQueries(nums []int, queries []int) []int {
    n := len(nums)
    numsPos := make(map[int][]int)

    for i := 0; i < n; i++ {
        numsPos[nums[i]] = append(numsPos[nums[i]], i)
    }

    for k, pos := range numsPos {
        x := pos[0]
        pos = append([]int{pos[len(pos)-1] - n}, pos...)
        pos = append(pos, x+n)
        numsPos[k] = pos
    }

    for i := 0; i < len(queries); i++ {
        x := nums[queries[i]]
        posList := numsPos[x]
        if (len(posList) == 3) {
            queries[i] = -1
            continue
        }
        pos := sort.SearchInts(posList, queries[i])
        queries[i] = min(posList[pos+1]-posList[pos], posList[pos]-posList[pos-1])
    }

    return queries
}
