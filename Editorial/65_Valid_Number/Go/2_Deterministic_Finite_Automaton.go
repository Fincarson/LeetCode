func isNumber(s string) bool {
    // This is the DFA we have designed above
    dfa := []map[string]int{
        {"digit": 1, "sign": 2, "dot": 3},
        {"digit": 1, "dot": 4, "exponent": 5},
        {"digit": 1, "dot": 3},
        {"digit": 4},
        {"digit": 4, "exponent": 5},
        {"sign": 6, "digit": 7},
        {"digit": 7},
        {"digit": 7},
    }
    currentState := 0
    var group string
    for _, c := range s {
        if c >= '0' && c <= '9' {
            group = "digit"
        } else if c == '+' || c == '-' {
            group = "sign"
        } else if c == 'e' || c == 'E' {
            group = "exponent"
        } else if c == '.' {
            group = "dot"
        } else {
            return false
        }
        if _, ok := dfa[currentState][group]; !ok {
            return false
        }
        currentState = dfa[currentState][group]
    }
    return currentState == 1 || currentState == 4 || currentState == 7
}
