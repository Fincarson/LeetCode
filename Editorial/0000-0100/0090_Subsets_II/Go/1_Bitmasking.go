func subsetsWithDup(nums []int) [][]int {
    n := len(nums)
    // Sort the generated subset. This will help to identify duplicates.
    sort.Ints(nums)
    subsets := make([][]int, 0)
    maxNumberOfSubsets := 1 << n
    // To store the previously seen sets.
    seen := make(map[string]bool)
    for subsetIndex := 0; subsetIndex < maxNumberOfSubsets; subsetIndex++ {
        // Append subset corresponding to that bitmask.
        currentSubset := make([]int, 0)
        hashcode := ""
        for j := 0; j < n; j++ {
            // Generate the bitmask
            mask := 1 << j
            isSet := mask & subsetIndex
            if isSet != 0 {
                currentSubset = append(currentSubset, nums[j])
                // Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                hashcode += strconv.Itoa(nums[j]) + ","
            }
        }
        if _, ok := seen[hashcode]; !ok {
            subsets = append(subsets, currentSubset)
            seen[hashcode] = true
        }
    }
    return subsets
}
