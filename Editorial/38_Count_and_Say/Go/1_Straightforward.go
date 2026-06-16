func countAndSay(n int) string {
    currentString := "1"
    for i := 2; i <= n; i++ {
        nextString := ""
        for j, k := 0, 0; j < len(currentString); j = k {
            for k < len(currentString) && currentString[k] == currentString[j] {
                k++
            }
            next := fmt.Sprintf("%d%c", k-j, currentString[j])
            nextString += next
        }
        currentString = nextString
    }
    return currentString
}
