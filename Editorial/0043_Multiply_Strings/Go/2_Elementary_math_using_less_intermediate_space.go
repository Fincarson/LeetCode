// Function to add two strings.
func addStrings(num1 []int, num2 []int) []int {
    ans := []int{}
    carry := 0

    for i := 0; i < len(num1) || i < len(num2) || carry != 0; i++ {
        // If num2 is shorter than num1 or vice versa, use 0 as the current digit.
        digit1, digit2 := 0, 0
        if i < len(num1) {
            digit1 = num1[i]
        }
        if i < len(num2) {
            digit2 = num2[i]
        }

        // Add current digits of both numbers.
        sum := digit1 + digit2 + carry
        // Set carry equal to the tens place digit of sum.
        carry = sum / 10
        // Append the ones place digit of sum to answer.
        ans = append(ans, sum%10)
    }

    if carry != 0 {
        ans = append(ans, carry)
    }
    return ans
}

// Multiply the current digit of secondNumber with firstNumber.
func multiplyOneDigit(
    firstNumber string,
    secondNumberDigit rune,
    numZeros int,
) []int {
    // Insert zeros at the beginning based on the current digit's place.
    currentResult := make([]int, numZeros)

    carry := 0
    for i := 0; i < len(firstNumber); i++ {
        firstNumberDigit := firstNumber[i] - '0'
        multiplication := int(
            secondNumberDigit-'0',
        )*int(
            firstNumberDigit,
        ) + carry
        // Set carry equal to the tens place digit of multiplication.
        carry = multiplication / 10
        // Append last digit to the current result.
        currentResult = append(currentResult, multiplication%10)
    }

    if carry != 0 {
        currentResult = append(currentResult, carry)
    }
    return currentResult
}

func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
        return "0"
    }

    // Reverse both the numbers.
    firstNumber := reverseString(num1)
    secondNumber := reverseString(num2)

    // To store the multiplication result of each digit of secondNumber with firstNumber.
    N := len(firstNumber) + len(secondNumber)
    ans := make([]int, N)

    // For each digit in secondNumber, multiply the digit by firstNumber and
    // add the multiplication result to ans.
    for i, digit := range secondNumber {
        result := multiplyOneDigit(firstNumber, rune(digit), i)
        ans = addStrings(result, ans)
    }

    // Pop excess 0 from the rear of ans.
    if ans[len(ans)-1] == 0 {
        ans = ans[:len(ans)-1]
    }

    // Ans is in the reversed order.
    // Copy it in reverse order to get the final ans.
    var answer strings.Builder
    for i := len(ans) - 1; i >= 0; i-- {
        answer.WriteString(strconv.Itoa(ans[i]))
    }

    return answer.String()
}

func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
