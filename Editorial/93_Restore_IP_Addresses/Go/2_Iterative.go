func valid(s string, start int, length int) bool {
    if length > 1 && s[start] == '0' {
        return false
    }
    num := 0
    for i := start; i < start+length; i++ {
        num = num*10 + int(s[i]-'0')
    }
    return num >= 0 && num <= 255
}

func restoreIpAddresses(s string) []string {
    var ans []string
    length := len(s)
    for len1 := 1; len1 <= 3; len1++ {
        if len1 > length {
            break
        }
        if !valid(s, 0, len1) {
            continue
        }
        for len2 := 1; len2 <= 3; len2++ {
            if len1+len2 > length {
                break
            }
            if !valid(s, len1, len2) {
                continue
            }
            for len3 := 1; len3 <= 3; len3++ {
                restLen := length - len1 - len2 - len3
                if restLen < 1 ||
                    restLen > 3 { // IP address can't start or end with '.'
                    continue
                }
                if valid(s, len1+len2, len3) &&
                    valid(s, len1+len2+len3, restLen) {
                    ans = append(
                        ans,
                        s[:len1]+"."+s[len1:len1+len2]+"."+s[len1+len2:len1+len2+len3]+"."+s[len1+len2+len3:],
                    )
                }
            }
        }
    }
    return ans
}
