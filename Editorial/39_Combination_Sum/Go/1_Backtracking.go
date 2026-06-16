func combinationSum(candidates []int, target int) [][]int {
    var results [][]int
    var comb []int
    backtrack(target, comb, 0, candidates, &results)
    return results
}

func backtrack(
    remain int,
    comb []int,
    start int,
    candidates []int,
    results *[][]int,
) {
    if remain == 0 {
        // Make a deep copy of the current combination to add to results
        newComb := make([]int, len(comb))
        copy(newComb, comb)
        *results = append(*results, newComb)
        return
    } else if remain < 0 {
        // Exceed the scope, stop exploration.
        return
    }

    for i := start; i < len(candidates); i++ {
        // Add the number into the combination
        comb = append(comb, candidates[i])
        // Continue to explore with the updated combination
        backtrack(remain-candidates[i], comb, i, candidates, results)
        // Backtrack, remove the number from the combination
        comb = comb[:len(comb)-1]
    }
}
