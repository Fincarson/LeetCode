func evalRPN(tokens []string) int {
    OPERATIONS := map[string]func(int, int) int{
        "+": func(a, b int) int { return a + b },
        "-": func(a, b int) int { return a - b },
        "*": func(a, b int) int { return a * b },
        "/": func(a, b int) int { return a / b },
    }
    currentPosition := 0
    for len(tokens) > 1 {
        for _, exist := OPERATIONS[strings.TrimSpace(tokens[currentPosition])]; !exist; {
            currentPosition += 1
            _, exist = OPERATIONS[strings.TrimSpace(tokens[currentPosition])]
        }
        operator := strings.TrimSpace(tokens[currentPosition])
        operation, _ := OPERATIONS[operator]
        number1, _ := strconv.Atoi(tokens[currentPosition-2])
        number2, _ := strconv.Atoi(tokens[currentPosition-1])
        tokens[currentPosition] = fmt.Sprintf("%d", operation(number1, number2))
        tokens = append(tokens[:currentPosition-2], tokens[currentPosition:]...)
        currentPosition -= 1
    }
    result, _ := strconv.Atoi(tokens[0])
    return result
}
