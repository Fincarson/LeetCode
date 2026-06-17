func singleNumber(nums []int) int {
    freq := make(map[int]int)
    for _, num := range nums {
        freq[num]++
    }
    var loner int
    for num, count := range freq {
        if count == 1 {
            loner = num
            break
        }
    }
    return loner
}
