func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
        return "0"
    }
    firstNumber := []rune(num1)
    secondNumber := []rune(num2)
    // Reverse both the numbers.
    for i, j := 0, len(firstNumber)-1; i < j; i, j = i+1, j-1 {
        firstNumber[i], firstNumber[j] = firstNumber[j], firstNumber[i]
    }
    for i, j := 0, len(secondNumber)-1; i < j; i, j = i+1, j-1 {
        secondNumber[i], secondNumber[j] = secondNumber[j], secondNumber[i]
    }
    // To store the multiplication result of each digit of secondNumber with firstNumber.
    N := len(firstNumber) + len(secondNumber)
    answer := make([]rune, N)
    for i := range answer {
        answer[i] = '0'
    }
    for place2 := range secondNumber {
        digit2 := secondNumber[place2] - '0'
        // For each digit in secondNumber multiply the digit by all digits in firstNumber.
        for place1 := range firstNumber {
            digit1 := firstNumber[place1] - '0'
            // The number of zeros from multiplying to digits depends on the place of
            // digit2 in secondNumber and the place of the digit1 in firstNumber.
            currentPos := place1 + place2
            // The digit currently at position currentPos in the answer string
            // is carried over and summed with the current result.
            carry := answer[currentPos] - '0'
            multiplication := digit1*digit2 + carry
            // Set the ones place of the multiplication result.
            answer[currentPos] = rune(multiplication%10) + '0'
            // Carry the tens place of the multiplication result by
            // adding it to the next position in the answer array.
            answer[currentPos+1] += rune(multiplication / 10)
        }
    }
    // Pop excess 0s from the rear of answer.
    if answer[len(answer)-1] == '0' {
        answer = answer[:len(answer)-1]
    }
    // Ans is in the reversed order.
    // Reverse it to get the final ans.
    for i, j := 0, len(answer)-1; i < j; i, j = i+1, j-1 {
        answer[i], answer[j] = answer[j], answer[i]
    }
    return string(answer)
}
