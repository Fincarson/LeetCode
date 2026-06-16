func evalRPN(tokens []string) int {
    operations := map[string]func(int, int) int{
        "+": func(a, b int) int { return a + b },
        "-": func(a, b int) int { return a - b },
        "*": func(a, b int) int { return a * b },
        "/": func(a, b int) int { return a / b },
    }
    stack := []int{}
    for _, token := range tokens {
        if operation, exists := operations[token]; exists {
            num1 := stack[len(stack)-2]
            num2 := stack[len(stack)-1]
            stack = stack[:len(stack)-2]
            result := operation(num1, num2)
            stack = append(stack, result)
        } else {
            num, _ := strconv.Atoi(token)
            stack = append(stack, num)
        }
    }
    return stack[0]
}
