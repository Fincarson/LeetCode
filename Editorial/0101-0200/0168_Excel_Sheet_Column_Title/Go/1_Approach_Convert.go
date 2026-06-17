func convertToTitle(columnNumber int) string {
    ans := []byte{}

    for columnNumber > 0 {
        columnNumber--
        // Get the last character and append it at the end of string.
        ans = append(ans, byte((columnNumber%26)+'A'))
        columnNumber /= 26
    }

    // Reverse it, as we appended characters in reverse order.
    for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
        ans[i], ans[j] = ans[j], ans[i]
    }

    return string(ans)
}
