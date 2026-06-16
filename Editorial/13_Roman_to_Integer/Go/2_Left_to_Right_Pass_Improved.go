func romanToInt(s string) int {
    values := map[string]int{
        "I":  1,
        "V":  5,
        "X":  10,
        "L":  50,
        "C":  100,
        "D":  500,
        "M":  1000,
        "IV": 4,
        "IX": 9,
        "XL": 40,
        "XC": 90,
        "CD": 400,
        "CM": 900,
    }
    total := 0
    i := 0
    for i < len(s) {
        if i < len(s)-1 {
            substring := s[i : i+2]
            vals, ok := values[substring]
            if ok {
                total += vals
                i += 2
                continue
            }
        }
        val := values[string(s[i])]
        total += val
        i++
    }
    return total
}
