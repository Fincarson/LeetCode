func is_Interleave(
    s1 string,
    i int,
    s2 string,
    j int,
    res string,
    s3 string,
) bool {
    // If result matches with third string and we have reached the end of the all strings, return true.
    if res == s3 && i == len(s1) && j == len(s2) {
        return true
    }
    ans := false
    // Recurse for s1 & s2 if "ans" is false
    if i < len(s1) {
        ans = is_Interleave(s1, i+1, s2, j, res+string(s1[i]), s3)
    }
    if !ans && j < len(s2) {
        ans = is_Interleave(s1, i, s2, j+1, res+string(s2[j]), s3)
    }
    return ans
}

func isInterleave(s1 string, s2 string, s3 string) bool {
    // Check if sum of sizes of two strings is equal to the size of third string.
    if len(s1)+len(s2) != len(s3) {
        return false
    }
    return is_Interleave(s1, 0, s2, 0, "", s3)
}
