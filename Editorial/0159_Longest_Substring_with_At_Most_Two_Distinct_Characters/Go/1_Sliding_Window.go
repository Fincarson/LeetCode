func lengthOfLongestSubstringTwoDistinct(s string) int {
    n := len(s)
    if n < 3 {
        return n
    }

    // sliding window left and right pointers
    left := 0
    right := 0
    // hashmap character -> its rightmost position
    // in the sliding window
    hashmap := make(map[rune]int)

    max_len := 2

    for right < n {
        // when the slidewindow contains less than 3 characters
        hashmap[rune(s[right])] = right
        right++

        // slidewindow contains 3 characters
        if len(hashmap) == 3 {
            // delete the leftmost character
            del_idx := n
            for _, v := range hashmap {
                if v < del_idx {
                    del_idx = v
                }
            }

            delete(hashmap, rune(s[del_idx]))
            left = del_idx + 1
        }

        current_len := right - left
        if current_len > max_len {
            max_len = current_len
        }
    }

    return max_len
}
