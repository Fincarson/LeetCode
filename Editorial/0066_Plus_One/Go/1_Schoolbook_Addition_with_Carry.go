func plusOne(digits []int) []int {
    n := len(digits)
    // move along the input array starting from the end
    for i := n - 1; i >= 0; i-- {
        // set all the nines at the end of array to zeros
        if digits[i] == 9 {
            digits[i] = 0
        } else {
            // here we have the rightmost not-nine
            // increase this rightmost not-nine by 1
            digits[i]++
            // and the job is done
            return digits
        }
    }
    // We're here because all the digits are nines
    digits = append([]int{1}, digits...)
    return digits
}
