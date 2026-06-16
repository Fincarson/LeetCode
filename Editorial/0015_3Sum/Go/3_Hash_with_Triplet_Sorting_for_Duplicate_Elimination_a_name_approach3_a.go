func threeSum(nums []int) [][]int {
    res := make(map[[3]int]int)
    dups := make(map[int]bool)
    seen := make(map[int]int)

    for i := 0; i < len(nums); i++ {
        if _, ok := dups[nums[i]]; !ok {
            dups[nums[i]] = true
            for j := i + 1; j < len(nums); j++ {
                complement := -nums[i] - nums[j]
                if v, ok := seen[complement]; ok && v == i {
                    triplet := []int{nums[i], nums[j], complement}
                    sort.Ints(triplet)
                    res[[3]int{triplet[0], triplet[1], triplet[2]}] = 1
                }
                seen[nums[j]] = i
            }
        }
    }

    keys := make([][]int, 0)
    for k := range res {
        keys = append(keys, []int{k[0], k[1], k[2]})
    }

    return keys
}
