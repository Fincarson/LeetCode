func majorityElement(nums []int) int {
    var majority_element int32 = 0
    for i := 0; i < 32; i++ {
        bit := int32(1 << i)

        // Count how many numbers have this bit set.
        bit_count := 0
        for _, num := range nums {
            if (int32(num) & bit) != 0 {
                bit_count++
            }
        }

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if bit_count > len(nums)/2 {
            majority_element |= bit
        }
    }

    return int(majority_element)
}
