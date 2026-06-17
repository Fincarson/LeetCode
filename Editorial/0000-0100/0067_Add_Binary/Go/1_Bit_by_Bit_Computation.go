func addBinary(a string, b string) string {
    n, m := len(a), len(b)
    if n < m {
        return addBinary(b, a)
    }

    var result strings.Builder
    carry, j := 0, m-1
    for i := n - 1; i >= 0; i-- {
        if a[i] == '1' {
            carry++
        }
        if j >= 0 && b[j] == '1' {
            carry++
        }
        j--
        result.WriteByte('0' + byte(carry%2))
        carry /= 2
    }
    if carry == 1 {
        result.WriteByte('1')
    }
    // Convert result to string and reverse it
    s := result.String()
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
