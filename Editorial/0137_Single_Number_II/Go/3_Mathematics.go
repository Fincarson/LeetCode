func singleNumber(nums []int) int {
    unique := map[int]bool{}
    var sum, uniqueSum int
    for _, num := range nums {
        if _, exist := unique[num]; !exist {
            unique[num] = true
            uniqueSum += num
        }
        sum += num
    }
    return (3*uniqueSum - sum) / 2
}
