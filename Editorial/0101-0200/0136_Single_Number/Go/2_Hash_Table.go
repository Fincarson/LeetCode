func singleNumber(nums []int) int {
    hash_table := make(map[int]int)
    for _, num := range nums {
        hash_table[num]++
    }
    for _, num := range nums {
        if hash_table[num] == 1 {
            return num
        }
    }
    return 0
}
