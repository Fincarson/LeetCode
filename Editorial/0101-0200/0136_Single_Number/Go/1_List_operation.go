func singleNumber(nums []int) int {
    no_duplicate_list := []int{}
    for _, i := range nums {
        found := false
        for j, x := range no_duplicate_list {
            if i == x {
                found = true
                no_duplicate_list = append(
                    no_duplicate_list[:j],
                    no_duplicate_list[j+1:]...)
                break
            }
        }
        if !found {
            no_duplicate_list = append(no_duplicate_list, i)
        }
    }
    return no_duplicate_list[0]
}
