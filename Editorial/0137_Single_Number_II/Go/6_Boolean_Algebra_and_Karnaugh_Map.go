func singleNumber(nums []int) int {
    // Count (modulo 3) bits
    msb, lsb := 0, 0
    // Process Every Num and update count bits
    for _, num := range nums {
        new_lsb := (^msb & ^lsb & num) | (lsb & ^num)
        new_msb := (lsb & num) | (msb & ^num)
        lsb = new_lsb
        msb = new_msb
    }
    // Return lsb as the answer
    return lsb
}
