func longestPalindrome(s string) string {
    sPrime := "#"
    for _, c := range s {
        sPrime = sPrime + string(c) + "#"
    }

    n := len(sPrime)
    palindromeRadii := make([]int, n)
    center := 0
    radius := 0

    for i := 0; i < n; i++ {
        mirror := 2*center - i

        if i < radius {
            palindromeRadii[i] = min(radius-i, palindromeRadii[mirror])
        }

        for i+1+palindromeRadii[i] < n && i-1-palindromeRadii[i] >= 0 &&
            sPrime[i+1+palindromeRadii[i]] == sPrime[i-1-palindromeRadii[i]] {
            palindromeRadii[i]++
        }

        if i+palindromeRadii[i] > radius {
            center = i
            radius = i + palindromeRadii[i]
        }
    }

    maxLength := 0
    centerIndex := 0
    for i := 0; i < n; i++ {
        if palindromeRadii[i] > maxLength {
            maxLength = palindromeRadii[i]
            centerIndex = i
        }
    }

    startIndex := (centerIndex - maxLength) / 2
    longestPalindrome := s[startIndex : startIndex+maxLength]

    return longestPalindrome
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
