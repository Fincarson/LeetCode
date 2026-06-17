# 43. Multiply Strings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/multiply-strings/)  
`Math` `String` `Simulation`

**Problem Link:** [LeetCode 43 - Multiply Strings](https://leetcode.com/problems/multiply-strings/)

## Problem

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

### Example 1

```text
Input: num1 = "2", num2 = "3"
Output: "6"
```

### Example 2

```text
Input: num1 = "123", num2 = "456"
Output: "56088"
```

## Constraints

- 1 <= num1.length, num2.length <= 200
- num1 and num2 consist of digits only.
- Both num1 and num2 do not contain any leading zero, except the number 0 itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Plus One](https://leetcode.com/problems/plus-one/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Add Binary](https://leetcode.com/problems/add-binary/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Add Strings](https://leetcode.com/problems/add-strings/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Apply Discount to Prices](https://leetcode.com/problems/apply-discount-to-prices/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 43. Multiply Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Elementary Math | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Elementary math using less intermediate space | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Sum the products from all pairs of digits | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Elementary Math

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Custom function to reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Sum the results from multiple digit multiplication
int* sumResults(int** results, int* sizes, int resultsCount, int* finalSize) {
    // Initialize answer with the last result
    int* answer = malloc(sizes[resultsCount - 1] * sizeof(int));
    memcpy(answer, results[resultsCount - 1],
           sizes[resultsCount - 1] * sizeof(int));
    int answerSize = sizes[resultsCount - 1];

    for (int j = 0; j < resultsCount - 1; j++) {
        int* result = results[j];
        int resultSize = sizes[j];
        int maxSize = (answerSize > resultSize ? answerSize : resultSize) + 1;
        int* newAnswer = calloc(maxSize, sizeof(int));
        int carry = 0;

        for (int i = 0; i < maxSize - 1; i++) {
            int digit1 = i < resultSize ? result[i] : 0;
            int digit2 = i < answerSize ? answer[i] : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            newAnswer[i] = sum % 10;
        }

        if (carry != 0) {
            newAnswer[maxSize - 1] = carry;
        } else {
            maxSize--;
        }

        free(answer);
        answer = newAnswer;
        answerSize = maxSize;
    }

    *finalSize = answerSize;
    return answer;
}

// Multiply a single digit with a number represented as a string
int* multiplyOneDigit(char* number, char digit, int numZeros, int* size) {
    int digitValue = digit - '0';
    int numberLen = strlen(number);
    int* result = calloc(numberLen + numZeros + 1, sizeof(int));
    int carry = 0, index = numZeros;

    for (int i = 0; i < numberLen; i++, index++) {
        int numDigit = number[i] - '0';
        int product = digitValue * numDigit + carry;
        result[index] = product % 10;
        carry = product / 10;
    }

    if (carry > 0) {
        result[index++] = carry;
    }

    *size = index;
    return result;
}

// Main multiplication function
char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        return strdup("0");
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int** results = malloc(len2 * sizeof(int*));
    int* sizes = malloc(len2 * sizeof(int));

    // Reverse the numbers
    char* firstNumber = strdup(num1);
    reverseString(firstNumber);
    char* secondNumber = strdup(num2);
    reverseString(secondNumber);

    for (int i = 0; i < len2; i++) {
        results[i] =
            multiplyOneDigit(firstNumber, secondNumber[i], i, &sizes[i]);
    }

    int finalSize;
    int* finalResult = sumResults(results, sizes, len2, &finalSize);

    char* answer = malloc(finalSize + 1);
    for (int i = 0; i < finalSize; i++) {
        answer[i] = finalResult[finalSize - 1 - i] +
                    '0';  // Reversing the result into the final answer
    }
    answer[finalSize] = '\0';

    // Free allocated memory
    free(firstNumber);
    free(secondNumber);
    for (int i = 0; i < len2; i++) {
        free(results[i]);
    }
    free(results);
    free(sizes);
    free(finalResult);

    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Calculate the sum of all of the results from multiplyOneDigit.
    string sumResults(vector<vector<int>>& results) {
        // Initialize answer as a number from results.
        vector<int> answer = results.back();
        vector<int> newAnswer;
        results.pop_back();

        // Sum each digit from answer and result
        for (vector<int> result : results) {
            newAnswer.clear();
            int carry = 0;

            for (int i = 0; i < answer.size() || i < result.size(); ++i) {
                // If answer is shorter than result or vice versa, use 0 as the
                // current digit.
                int digit1 = i < result.size() ? result[i] : 0;
                int digit2 = i < answer.size() ? answer[i] : 0;
                // Add current digits of both numbers.
                int sum = digit1 + digit2 + carry;
                // Set carry equal to the tens place digit of sum.
                carry = sum / 10;
                // Append the ones place digit of sum to answer.
                newAnswer.push_back(sum % 10);
            }

            if (carry) {
                newAnswer.push_back(carry);
            }
            answer = newAnswer;
        }

        // Convert answer to a string.
        string finalAnswer;
        for (int digit : answer) {
            finalAnswer.push_back(digit + '0');
        }
        return finalAnswer;
    }

    // Multiply the current digit of secondNumber with firstNumber.
    vector<int> multiplyOneDigit(string& firstNumber, char& secondNumberDigit,
                                 int numZeros) {
        // Insert zeros at the beginning based on the current digit's place.
        vector<int> currentResult(numZeros, 0);
        int carry = 0;

        // Multiply firstNumber with the current digit of secondNumber.
        for (char firstNumberDigit : firstNumber) {
            int multiplication =
                (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
            // Set carry equal to the tens place digit of multiplication.
            carry = multiplication / 10;
            // Append last digit to the current result.
            currentResult.push_back(multiplication % 10);
        }

        if (carry) {
            currentResult.push_back(carry);
        }
        return currentResult;
    }

public:
    string multiply(string firstNumber, string secondNumber) {
        if (firstNumber == "0" || secondNumber == "0") {
            return "0";
        }

        // Reverse both numbers.
        reverse(firstNumber.begin(), firstNumber.end());
        reverse(secondNumber.begin(), secondNumber.end());

        // For each digit in secondNumber, multipy the digit by firstNumber and
        // store the multiplication result (reversed) in results.
        vector<vector<int>> results;
        for (int i = 0; i < secondNumber.size(); ++i) {
            results.push_back(
                multiplyOneDigit(firstNumber, secondNumber[i], i));
        }

        // Add all the results in the results array, and store the sum in the
        // answer string.
        string answer = sumResults(results);

        // answer is reversed, so reverse it to get the final answer.
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    // Calculate the sum of all of the results from multiplyOneDigit.
    private List<int> SumResults(List<List<int>> results) {
        // Initialize answer as a number from results.
        List<int> answer = new List<int>(results[results.Count - 1]);
        List<int> newAnswer;
        for (int j = 0; j < results.Count - 1; ++j) {
            List<int> result = new List<int>(results[j]);
            newAnswer = new List<int>();
            int carry = 0;
            for (int i = 0; i < answer.Count || i < result.Count; ++i) {
                int digit1 = i < result.Count ? result[i] : 0;
                int digit2 = i < answer.Count ? answer[i] : 0;
                int sum = digit1 + digit2 + carry;
                carry = sum / 10;
                newAnswer.Add(sum % 10);
            }

            if (carry != 0) {
                newAnswer.Add(carry);
            }

            answer = newAnswer;
        }

        return answer;
    }

    private List<int> MultiplyOneDigit(char[] firstNumber,
                                       char secondNumberDigit, int numZeros) {
        List<int> currentResult = Enumerable.Repeat(0, numZeros).ToList();
        int carry = 0;
        for (int i = 0; i < firstNumber.Length; i++) {
            int multiplication =
                (secondNumberDigit - '0') * (firstNumber[i] - '0') + carry;
            carry = multiplication / 10;
            currentResult.Add(multiplication % 10);
        }

        if (carry != 0) {
            currentResult.Add(carry);
        }

        return currentResult;
    }

    public string Multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        char[] firstNumber = num1.ToCharArray();
        Array.Reverse(firstNumber);
        char[] secondNumber = num2.ToCharArray();
        Array.Reverse(secondNumber);
        List<List<int>> results = new List<List<int>>();
        for (int i = 0; i < secondNumber.Length; ++i) {
            results.Add(MultiplyOneDigit(firstNumber, secondNumber[i], i));
        }

        List<int> answer = SumResults(results);
        return string.Join(
            "", answer.Select(t => t.ToString()).ToArray().Reverse());
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sumResults(results [][]int) string {
    // Initialize answer as a number from results.
    answer := results[len(results)-1]
    results = results[:len(results)-1]
    var newAnswer []int
    // Sum each digit from answer and result
    for _, result := range results {
        newAnswer = nil
        var carry int
        for i := 0; i < len(answer) || i < len(result); i++ {
            var digit1, digit2 int
            // If answer is shorter than result or vice versa, use 0 as the current digit.
            if i < len(result) {
                digit1 = result[i]
            } else {
                digit1 = 0
            }
            if i < len(answer) {
                digit2 = answer[i]
            } else {
                digit2 = 0
            }
            // Add current digits of both numbers.
            sum := digit1 + digit2 + carry
            // Set carry equal to the tens place digit of sum.
            carry = sum / 10
            // Append the ones place digit of sum to answer.
            newAnswer = append(newAnswer, sum%10)
        }
        if carry > 0 {
            newAnswer = append(newAnswer, carry)
        }
        answer = newAnswer
    }
    // Convert answer to a string.
    finalAnswer := ""
    for _, digit := range answer {
        finalAnswer += strconv.Itoa(digit)
    }
    return finalAnswer
}

func multiplyOneDigit(
    firstNumber string,
    secondNumberDigit rune,
    numZeros int,
) []int {
    // Insert zeros at the beginning based on the current digit's place.
    currentResult := make([]int, numZeros)
    var carry int
    // Multiply firstNumber with the current digit of secondNumber.
    for _, firstNumberDigit := range firstNumber {
        multiplication := (int(secondNumberDigit-'0') * int(firstNumberDigit-'0')) + carry
        // Set carry equal to the tens place digit of multiplication.
        carry = multiplication / 10
        // Append last digit to the current result.
        currentResult = append(currentResult, multiplication%10)
    }
    if carry > 0 {
        currentResult = append(currentResult, carry)
    }
    return currentResult
}

func multiply(firstNumber, secondNumber string) string {
    if firstNumber == "0" || secondNumber == "0" {
        return "0"
    }
    // Reverse both numbers.
    firstNumber = reverseString(firstNumber)
    secondNumber = reverseString(secondNumber)
    // For each digit in secondNumber, multipy the digit by firstNumber and
    // store the multiplication result (reversed) in results.
    var results [][]int
    for i, secondNumberDigit := range secondNumber {
        results = append(
            results,
            multiplyOneDigit(firstNumber, rune(secondNumberDigit), i),
        )
    }
    // Add all the results in the results array, and store the sum in the answer string.
    answer := sumResults(results)
    // answer is reversed, so reverse it to get the final answer.
    return reverseString(answer)
}

func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Calculate the sum of all of the results from multiplyOneDigit.
    private StringBuilder sumResults(ArrayList<ArrayList<Integer>> results) {
        // Initialize answer as a number from results.
        ArrayList<Integer> answer = new ArrayList<>(
            results.get(results.size() - 1)
        );
        ArrayList<Integer> newAnswer = new ArrayList<>();

        // Sum each digit from answer and result
        for (int j = 0; j < results.size() - 1; ++j) {
            ArrayList<Integer> result = new ArrayList<>(results.get(j));
            newAnswer = new ArrayList<>();

            int carry = 0;

            for (int i = 0; i < answer.size() || i < result.size(); ++i) {
                // If answer is shorter than result or vice versa, use 0 as the current digit.
                int digit1 = i < result.size() ? result.get(i) : 0;
                int digit2 = i < answer.size() ? answer.get(i) : 0;
                // Add current digits of both numbers.
                int sum = digit1 + digit2 + carry;
                // Set carry equal to the tens place digit of sum.
                carry = sum / 10;
                // Append the ones place digit of sum to answer.
                newAnswer.add(sum % 10);
            }

            if (carry != 0) {
                newAnswer.add(carry);
            }
            answer = newAnswer;
        }

        // Convert answer to a string.
        StringBuilder finalAnswer = new StringBuilder();
        for (int digit : answer) {
            finalAnswer.append(digit);
        }
        return finalAnswer;
    }

    // Multiply the current digit of secondNumber with firstNumber.
    ArrayList<Integer> multiplyOneDigit(
        StringBuilder firstNumber,
        char secondNumberDigit,
        int numZeros
    ) {
        // Insert zeros at the beginning based on the current digit's place.
        ArrayList<Integer> currentResult = new ArrayList<>();
        for (int i = 0; i < numZeros; ++i) {
            currentResult.add(0);
        }

        int carry = 0;

        // Multiply firstNumber with the current digit of secondNumber.
        for (int i = 0; i < firstNumber.length(); ++i) {
            char firstNumberDigit = firstNumber.charAt(i);
            int multiplication =
                (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
            // Set carry equal to the tens place digit of multiplication.
            carry = multiplication / 10;
            // Append last digit to the current result.
            currentResult.add(multiplication % 10);
        }

        if (carry != 0) {
            currentResult.add(carry);
        }
        return currentResult;
    }

    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        StringBuilder firstNumber = new StringBuilder(num1);
        StringBuilder secondNumber = new StringBuilder(num2);

        // Reverse both the numbers.
        firstNumber.reverse();
        secondNumber.reverse();

        // For each digit in secondNumber, multipy the digit by firstNumber and
        // store the multiplication result (reversed) in results.
        ArrayList<ArrayList<Integer>> results = new ArrayList<>();
        for (int i = 0; i < secondNumber.length(); ++i) {
            results.add(
                multiplyOneDigit(firstNumber, secondNumber.charAt(i), i)
            );
        }

        // Add all the results in the results array, and store the sum in the answer string.
        StringBuilder answer = sumResults(results);

        // answer is reversed, so reverse it to get the final answer.
        answer.reverse();
        return answer.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Calculate the sum of all of the results from multiplyOneDigit.
let sumResults = function (results) {
    // Initialize answer as a number from results.
    let answer = [...results[results.length - 1]];
    let newAnswer = [];

    // Sum each digit from answer and result
    for (let j = 0; j < results.length - 1; ++j) {
        let result = [...results[j]];
        newAnswer = [];

        let carry = 0;

        for (let i = 0; i < answer.length || i < result.length; ++i) {
            // If answer is shorter than result or vice versa, use 0 as the current digit.
            let digit1 = i < result.length ? result[i] : 0;
            let digit2 = i < answer.length ? answer[i] : 0;
            // Add current digits of both numbers.
            let sum = digit1 + digit2 + carry;
            // Set carry equal to the tens place digit of sum.
            carry = Math.floor(sum / 10);
            // Append the ones place digit of sum to answer.
            newAnswer.push(sum % 10);
        }

        if (carry != 0) {
            newAnswer.push(carry);
        }
        answer = newAnswer;
    }

    return answer;
};

// Multiply the current digit of secondNumber with firstNumber.
let multiplyOneDigit = function (firstNumber, secondNumberDigit, numZeros) {
    // Insert zeros at the beginning based on the current digit's place.
    let currentResult = [];
    for (let i = 0; i < numZeros; ++i) {
        currentResult.push(0);
    }

    let carry = 0;

    // Multiply firstNumber with the current digit of secondNumber.
    for (let i = 0; i < firstNumber.length; ++i) {
        let multiplication =
            Number(secondNumberDigit) * Number(firstNumber[i]) + carry;
        // Set carry equal to the tens place digit of multiplication.
        carry = Math.floor(multiplication / 10);
        // Append last digit to the current result.
        currentResult.push(multiplication % 10);
    }

    if (carry) {
        currentResult.push(carry);
    }
    return currentResult;
};

let multiply = function (num1, num2) {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }

    let firstNumber = [...num1];
    let secondNumber = [...num2];

    // Reverse both the numbers.
    firstNumber.reverse();
    secondNumber.reverse();

    // For each digit in secondNumber, multipy the digit by firstNumber and
    // store the multiplication result (reversed) in results.
    let results = [];
    for (let i = 0; i < secondNumber.length; ++i) {
        results.push(multiplyOneDigit(firstNumber, secondNumber[i], i));
    }

    // Add all the results in the results array, and store the sum in the answer string.
    let answer = sumResults(results);

    // answer is reversed, so reverse it to get the final answer.
    answer.reverse();
    return answer.join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        # Reverse both numbers.
        first_number = num1[::-1]
        second_number = num2[::-1]

        # For each digit in second_number, multipy the digit by first_number and then
        # store the multiplication result (reversed) in the results array.
        results = []
        for index, digit in enumerate(second_number):
            results.append(self.multiply_one_digit(digit, index, first_number))

        # Add all of the results together to get our final answer (in reverse order)
        answer = self.sum_results(results)

        # Reverse answer and join the digits to get the final answer.
        return "".join(str(digit) for digit in reversed(answer))

    def multiply_one_digit(
        self, digit2: str, num_zeros: int, first_number: List[str]
    ) -> List[int]:
        """Multiplies first_number by a digit from second_number (digit2)."""
        # Insert zeros at the beginning of the current result based on the current digit's place.
        current_result = [0] * num_zeros
        carry = 0

        # Multiply each digit in first_number with the current digit of the second_number.
        for digit1 in first_number:
            multiplication = int(digit1) * int(digit2) + carry
            # Set carry equal to the tens place digit of multiplication.
            carry = multiplication // 10
            # Append last digit to the current result.
            current_result.append(multiplication % 10)

        if carry != 0:
            current_result.append(carry)
        return current_result

    def sum_results(self, results: List[List[int]]) -> List[int]:
        # Initialize answer as a number from results.
        answer = results.pop()

        # Add each result to answer one at a time.
        for result in results:
            new_answer = []
            carry = 0

            # Sum each digit from answer and result. Note: zip_longest is the
            # same as zip, except that it pads the shorter list with fillvalue.
            for digit1, digit2 in zip_longest(result, answer, fillvalue=0):
                # Add current digit from both numbers.
                curr_sum = digit1 + digit2 + carry
                # Set carry equal to the tens place digit of curr_sum.
                carry = curr_sum // 10
                # Append the ones place digit of curr_sum to the new answer.
                new_answer.append(curr_sum % 10)

            if carry != 0:
                new_answer.append(carry)

            # Update answer to new_answer which equals answer + result
            answer = new_answer

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let sumResults = function (results: number[][]): number[] {
    let answer: number[] = [...results[results.length - 1]];
    let newAnswer: number[];
    for (let j = 0; j < results.length - 1; ++j) {
        let result: number[] = [...results[j]];
        newAnswer = [];
        let carry = 0;
        for (let i = 0; i < answer.length || i < result.length; ++i) {
            let digit1 = i < result.length ? result[i] : 0;
            let digit2 = i < answer.length ? answer[i] : 0;
            let sum = digit1 + digit2 + carry;
            carry = Math.floor(sum / 10);
            newAnswer.push(sum % 10);
        }
        if (carry !== 0) {
            newAnswer.push(carry);
        }
        answer = newAnswer;
    }
    return answer;
};
let multiplyOneDigit = function (
    firstNumber: string[],
    secondNumberDigit: string,
    numZeros: number,
): number[] {
    const currentResult: number[] = [];
    for (let i = 0; i < numZeros; ++i) {
        currentResult.push(0);
    }
    let carry = 0;
    for (let i = 0; i < firstNumber.length; ++i) {
        const multiplication =
            Number(secondNumberDigit) * Number(firstNumber[i]) + carry;
        carry = Math.floor(multiplication / 10);
        currentResult.push(multiplication % 10);
    }
    if (carry) {
        currentResult.push(carry);
    }
    return currentResult;
};
let multiply = function (num1: string, num2: string): string {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }
    let firstNumber = [...num1];
    firstNumber.reverse();
    let secondNumber = [...num2];
    secondNumber.reverse();
    let results: number[][] = [];
    for (let i = 0; i < secondNumber.length; ++i) {
        results.push(multiplyOneDigit(firstNumber, secondNumber[i], i));
    }
    const answer = sumResults(results);
    answer.reverse();
    return answer.join("");
};
```

</details>

<br>

## Approach 2: Elementary math using less intermediate space

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to add two strings.
void addStrings(int* num1, int num1Size, int* num2, int num2Size, int* result,
                int* resultSize) {
    int carry = 0;
    int i, sum, size = 0;

    for (i = 0; i < num1Size || i < num2Size || carry; ++i) {
        // If num1 is shorter than num2 or vice versa, use 0 as the current
        // digit.
        int digit1 = i < num1Size ? num1[i] : 0;
        int digit2 = i < num2Size ? num2[i] : 0;

        // Add current digits of both numbers.
        sum = digit1 + digit2 + carry;
        // Set carry equal to the tens place digit of sum.
        carry = sum / 10;
        // Append the ones place digit of sum to result.
        result[size++] = sum % 10;
    }

    *resultSize = size;
}

// Multiply the current digit of secondNumber with firstNumber.
void multiplyOneDigit(char* firstNumber, char secondNumberDigit, int numZeros,
                      int* result, int* resultSize) {
    int carry = 0;
    int size = numZeros;
    memset(result, 0,
           numZeros * sizeof(int));  // Insert zeros at the beginning.

    // Multiply firstNumber with the current digit of secondNumber.
    for (int i = 0; i < strlen(firstNumber); ++i) {
        int multiplication =
            (secondNumberDigit - '0') * (firstNumber[i] - '0') + carry;
        // Set carry equal to the tens place digit of multiplication.
        carry = multiplication / 10;
        // Append last digit to the current result.
        result[size++] = multiplication % 10;
    }

    if (carry) {
        result[size++] = carry;
    }

    *resultSize = size;
}

// Main multiplication function
char* multiply(char* firstNumber, char* secondNumber) {
    if (strcmp(firstNumber, "0") == 0 || strcmp(secondNumber, "0") == 0) {
        return strdup("0");
    }

    reverseString(firstNumber);
    reverseString(secondNumber);

    int maxLen = strlen(firstNumber) + strlen(secondNumber);
    int* ans = calloc(maxLen, sizeof(int));
    int ansSize = 0;

    // For each digit in secondNumber, multiply the digit by firstNumber and add
    // the multiplication result to ans.
    for (int i = 0; i < strlen(secondNumber); ++i) {
        int* tempResult = calloc(maxLen, sizeof(int));
        int tempResultSize;

        multiplyOneDigit(firstNumber, secondNumber[i], i, tempResult,
                         &tempResultSize);

        int* newAns = calloc(maxLen, sizeof(int));
        int newAnsSize;

        addStrings(ans, ansSize, tempResult, tempResultSize, newAns,
                   &newAnsSize);

        free(ans);
        ans = newAns;
        ansSize = newAnsSize;

        free(tempResult);
    }

    // Remove leading zeros from the result, if any.
    while (ansSize > 1 && ans[ansSize - 1] == 0) {
        ansSize--;
    }

    // Convert the numeric result back into a string
    char* answer = malloc(ansSize + 1);
    for (int i = ansSize - 1; i >= 0; --i) {
        answer[ansSize - 1 - i] = ans[i] + '0';
    }
    answer[ansSize] = '\0';

    free(ans);
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Function to add two strings.
    vector<int> addStrings(vector<int> num1, vector<int>& num2) {
        vector<int> ans;
        int carry = 0;

        for (int i = 0; i < num1.size() || i < num2.size() || carry; ++i) {
            // If num1 is shorter than num2 or vice versa, use 0 as the current
            // digit.
            int digit1 = i < num1.size() ? num1[i] : 0;
            int digit2 = i < num2.size() ? num2[i] : 0;

            // Add current digits of both numbers.
            int sum = digit1 + digit2 + carry;
            // Set carry equal to the tens place digit of sum.
            carry = sum / 10;
            // Append the ones place digit of sum to answer.
            ans.push_back(sum % 10);
        }

        return ans;
    }

    // Multiply the current digit of secondNumber with firstNumber.
    vector<int> multiplyOneDigit(string& firstNumber, char& secondNumberDigit,
                                 int numZeros) {
        // Insert zeros at the beginning based on the current digit's place.
        vector<int> currentResult(numZeros, 0);
        int carry = 0;

        // Multiply firstNumber with the current digit of secondNumber.
        for (char firstNumberDigit : firstNumber) {
            int multiplication =
                (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
            // Set carry equal to the tens place digit of multiplication.
            carry = multiplication / 10;
            // Append last digit to the current result.
            currentResult.push_back(multiplication % 10);
        }

        if (carry) {
            currentResult.push_back(carry);
        }
        return currentResult;
    }

public:
    string multiply(string firstNumber, string secondNumber) {
        if (firstNumber == "0" || secondNumber == "0") {
            return "0";
        }

        // Reverse both the numbers.
        reverse(firstNumber.begin(), firstNumber.end());
        reverse(secondNumber.begin(), secondNumber.end());

        // To store the multiplication result of each digit of secondNumber with
        // firstNumber.
        vector<int> ans(firstNumber.size() + secondNumber.size(), 0);

        // For each digit in secondNumber, multipy the digit by firstNumber and
        // add the multiplication result to ans.
        for (int i = 0; i < secondNumber.size(); ++i) {
            // Add the current result to final ans.
            ans = addStrings(multiplyOneDigit(firstNumber, secondNumber[i], i),
                             ans);
        }

        // Pop excess 0 from the rear of ans.
        if (ans[ans.size() - 1] == 0) {
            ans.pop_back();
        }

        // Ans is in the reversed order.
        // Copy it in reverse order to get the final ans.
        string answer;
        for (int i = ans.size() - 1; i >= 0; --i) {
            answer.push_back(ans[i] + '0');
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    // Function to add two strings.
    private List<int> AddStrings(List<int> num1, List<int> num2) {
        List<int> ans = new List<int>();
        int carry = 0;

        for (int i = 0; i < num1.Count || i < num2.Count || carry != 0; ++i) {
            // If num2 is shorter than num1 or vice versa, use 0 as the current
            // digit.
            int digit1 = i < num1.Count ? num1[i] : 0;
            int digit2 = i < num2.Count ? num2[i] : 0;

            // Add current digits of both numbers.
            int sum = digit1 + digit2 + carry;
            // Set carry equal to the tens place digit of sum.
            carry = sum / 10;
            // Append the ones place digit of sum to answer.
            ans.Add(sum % 10);
        }

        if (carry != 0) {
            ans.Add(carry);
        }

        return ans;
    }

    // Multiply the current digit of secondNumber with firstNumber.
    private List<int> MultiplyOneDigit(StringBuilder firstNumber,
                                       char secondNumberDigit, int numZeros) {
        // Insert zeros at the beginning based on the current digit's place.
        List<int> currentResult = new List<int>(new int[numZeros]);

        int carry = 0;

        // Multiply firstNumber with the current digit of secondNumber.
        for (int i = 0; i < firstNumber.Length; ++i) {
            int multiplication =
                (secondNumberDigit - '0') * (firstNumber[i] - '0') + carry;
            // Set carry equal to the tens place digit of multiplication.
            carry = multiplication / 10;
            // Append last digit to the current result.
            currentResult.Add(multiplication % 10);
        }

        if (carry != 0) {
            currentResult.Add(carry);
        }

        return currentResult;
    }

    public string Multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        // Reverse both the numbers.
        StringBuilder firstNumber =
            new StringBuilder(new string(num1.Reverse().ToArray()));
        StringBuilder secondNumber =
            new StringBuilder(new string(num2.Reverse().ToArray()));

        // To store the multiplication result of each digit of secondNumber with
        // firstNumber.
        int N = firstNumber.Length + secondNumber.Length;
        List<int> ans = new List<int>(new int[N]);

        // For each digit in secondNumber, multiply the digit by firstNumber and
        // add the multiplication result to ans.
        for (int i = 0; i < secondNumber.Length; ++i) {
            // Add the current result to final ans.
            ans = AddStrings(MultiplyOneDigit(firstNumber, secondNumber[i], i),
                             ans);
        }

        // Pop excess 0 from the rear of ans.
        if (ans[ans.Count - 1] == 0) {
            ans.RemoveAt(ans.Count - 1);
        }

        // Ans is in the reversed order.
        // Copy it in reverse order to get the final ans.
        StringBuilder answer = new StringBuilder();
        for (int i = ans.Count - 1; i >= 0; --i) {
            answer.Append(ans[i]);
        }

        return answer.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
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
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Function to add two strings.
    private ArrayList<Integer> addStrings(
        ArrayList<Integer> num1,
        ArrayList<Integer> num2
    ) {
        ArrayList<Integer> ans = new ArrayList<>();
        int carry = 0;

        for (int i = 0; i < num1.size() || i < num2.size(); ++i) {
            // If num2 is shorter than num1 or vice versa, use 0 as the current digit.
            int digit1 = i < num1.size() ? num1.get(i) : 0;
            int digit2 = i < num2.size() ? num2.get(i) : 0;

            // Add current digits of both numbers.
            int sum = digit1 + digit2 + carry;
            // Set carry equal to the tens place digit of sum.
            carry = sum / 10;
            // Append the ones place digit of sum to answer.
            ans.add(sum % 10);
        }

        if (carry != 0) {
            ans.add(carry);
        }
        return ans;
    }

    // Multiply the current digit of secondNumber with firstNumber.
    ArrayList<Integer> multiplyOneDigit(
        StringBuilder firstNumber,
        char secondNumberDigit,
        int numZeros
    ) {
        // Insert zeros at the beginning based on the current digit's place.
        ArrayList<Integer> currentResult = new ArrayList<>();
        for (int i = 0; i < numZeros; ++i) {
            currentResult.add(0);
        }

        int carry = 0;

        // Multiply firstNumber with the current digit of secondNumber.
        for (int i = 0; i < firstNumber.length(); ++i) {
            char firstNumberDigit = firstNumber.charAt(i);
            int multiplication =
                (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
            // Set carry equal to the tens place digit of multiplication.
            carry = multiplication / 10;
            // Append last digit to the current result.
            currentResult.add(multiplication % 10);
        }

        if (carry != 0) {
            currentResult.add(carry);
        }
        return currentResult;
    }

    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        StringBuilder firstNumber = new StringBuilder(num1);
        StringBuilder secondNumber = new StringBuilder(num2);

        // Reverse both the numbers.
        firstNumber.reverse();
        secondNumber.reverse();

        // To store the multiplication result of each digit of secondNumber with firstNumber.
        int N = firstNumber.length() + secondNumber.length();
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            ans.add(0);
        }

        // For each digit in secondNumber, multipy the digit by firstNumber and
        // add the multiplication result to ans.
        for (int i = 0; i < secondNumber.length(); ++i) {
            // Add the current result to final ans.
            ans = addStrings(
                multiplyOneDigit(firstNumber, secondNumber.charAt(i), i),
                ans
            );
        }

        // Pop excess 0 from the rear of ans.
        if (ans.get(ans.size() - 1) == 0) {
            ans.remove(ans.size() - 1);
        }

        // Ans is in the reversed order.
        // Copy it in reverse order to get the final ans.
        StringBuilder answer = new StringBuilder();

        for (int i = ans.size() - 1; i >= 0; --i) {
            answer.append(ans.get(i));
        }

        return answer.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Function to add two strings.
let addStrings = function (num1, num2) {
    let ans = [];
    let carry = 0;

    for (let i = 0; i < num1.length || i < num2.length; ++i) {
        // If num2 is shorter than num1 or vice versa, use 0 as the current digit.
        let digit1 = i < num1.length ? num1[i] : 0;
        let digit2 = i < num2.length ? num2[i] : 0;

        // Add current digits of both numbers.
        let sum = digit1 + digit2 + carry;
        // Set carry equal to the tens place digit of sum.
        carry = Math.floor(sum / 10);
        // Append the ones place digit of sum to answer.
        ans.push(sum % 10);
    }

    if (carry) {
        ans.push(carry);
    }
    return ans;
};

// Multiply the current digit of secondNumber with firstNumber.
let multiplyOneDigit = function (firstNumber, secondNumberDigit, numZeros) {
    // Insert zeros at the beginning based on the current digit's place.
    let currentResult = [];
    for (let i = 0; i < numZeros; ++i) {
        currentResult.push(0);
    }

    let carry = 0;

    // Multiply firstNumber with the current digit of secondNumber.
    for (let i = 0; i < firstNumber.length; ++i) {
        let firstNumberDigit = firstNumber[i];
        let multiplication =
            Number(secondNumberDigit) * Number(firstNumber[i]) + carry;
        // Set carry equal to the tens place digit of multiplication.
        carry = Math.floor(multiplication / 10);
        // Append last digit to the current result.
        currentResult.push(multiplication % 10);
    }

    if (carry) {
        currentResult.push(carry);
    }
    return currentResult;
};

let multiply = function (num1, num2) {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }

    let firstNumber = [...num1];
    let secondNumber = [...num2];

    // Reverse both the numbers.
    firstNumber.reverse();
    secondNumber.reverse();

    // To store the multiplication result of each digit of secondNumber with firstNumber.
    let N = firstNumber.length + secondNumber.length;
    let ans = new Array(N).fill(0);

    // For each digit in secondNumber, multipy the digit by firstNumber and
    // add the multiplication result to ans.
    for (let i = 0; i < secondNumber.length; ++i) {
        // Add the current result to final ans.
        ans = addStrings(
            multiplyOneDigit(firstNumber, secondNumber[i], i),
            ans,
        );
    }

    // Pop excess 0 from the rear of ans.
    if (ans[ans.length - 1] === 0) {
        ans.pop();
    }

    // Ans is in the reversed order.
    // Reverse it to get the final ans.
    ans.reverse();
    return ans.join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        # Reverse both numbers.
        first_number = num1[::-1]
        second_number = num2[::-1]

        # To store the multiplication result of each digit of secondNumber with firstNumber.
        N = len(first_number) + len(second_number)
        answer = [0] * N

        # Multiply each digit in second_number by the first_number
        # and add each result to answer
        for index, digit in enumerate(second_number):
            answer = self.addStrings(
                self.multiplyOneDigit(first_number, digit, index), answer
            )

        # Pop excess zero from the end of answer (if any).
        if answer[-1] == 0:
            answer.pop()

        # Ans is in the reversed order.
        # Reverse it to get the final answer.
        answer.reverse()
        return "".join(str(digit) for digit in answer)

    def multiplyOneDigit(self, first_number: str, digit2: str, num_zeros: int):
        # Insert 0s at the beginning based on the current digit's place.
        currentResult = [0] * num_zeros
        carry = 0

        # Multiply firstNumber with the current digit of secondNumber.
        for digit1 in first_number:
            multiplication = int(digit1) * int(digit2) + carry
            # Set carry equal to the tens place digit of multiplication.
            carry = multiplication // 10
            # Append the ones place digit of multiplication to the current result.
            currentResult.append(multiplication % 10)

        if carry != 0:
            currentResult.append(carry)
        return currentResult

    def addStrings(self, result: list, answer: list) -> list:
        carry = 0
        i = 0
        new_answer = []
        for digit1, digit2 in zip_longest(result, answer, fillvalue=0):
            # Add current digits of both numbers.
            curr_sum = digit1 + digit2 + carry
            carry = curr_sum // 10
            # Append last digit of curr_sum to the answer.
            new_answer.append(curr_sum % 10)
            i += 1

        return new_answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// Function to add two strings.
const addStrings = function (num1: number[], num2: number[]): number[] {
    let ans: number[] = [];
    let carry: number = 0;

    for (let i = 0; i < num1.length || i < num2.length; ++i) {
        // If num2 is shorter than num1 or vice versa, use 0 as the current digit.
        let digit1 = i < num1.length ? num1[i] : 0;
        let digit2 = i < num2.length ? num2[i] : 0;

        // Add current digits of both numbers.
        let sum = digit1 + digit2 + carry;
        // Set carry equal to the tens place digit of sum.
        carry = Math.floor(sum / 10);
        // Append the ones place digit of sum to answer.
        ans.push(sum % 10);
    }

    if (carry) {
        ans.push(carry);
    }
    return ans;
};

// Multiply the current digit of secondNumber with firstNumber.
const multiplyOneDigit = function (
    firstNumber: number[],
    secondNumberDigit: string,
    numZeros: number,
): number[] {
    // Insert zeros at the beginning based on the current digit's place.
    let currentResult: number[] = new Array(numZeros).fill(0);
    let carry: number = 0;

    // Multiply firstNumber with the current digit of secondNumber.
    for (let i = 0; i < firstNumber.length; ++i) {
        let firstNumberDigit = firstNumber[i];
        let multiplication =
            parseInt(secondNumberDigit) * firstNumberDigit + carry;
        // Set carry equal to the tens place digit of multiplication.
        carry = Math.floor(multiplication / 10);
        // Append last digit to the current result.
        currentResult.push(multiplication % 10);
    }

    if (carry) {
        currentResult.push(carry);
    }
    return currentResult;
};

function multiply(num1: string, num2: string): string {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }

    let firstNumber: number[] = [...num1].map((c) => parseInt(c));
    let secondNumber: number[] = [...num2].map((c) => parseInt(c));

    // Reverse both the numbers.
    firstNumber.reverse();
    secondNumber.reverse();

    // To store the multiplication result of each digit of secondNumber with firstNumber.
    let N: number = firstNumber.length + secondNumber.length;
    let ans: number[] = new Array(N).fill(0);

    // For each digit in secondNumber, multiply the digit by firstNumber and
    // add the multiplication result to ans.
    for (let i = 0; i < secondNumber.length; ++i) {
        // Add the current result to final ans.
        ans = addStrings(
            multiplyOneDigit(firstNumber, secondNumber[i].toString(), i),
            ans,
        );
    }

    // Pop excess 0 from the rear of ans.
    if (ans[ans.length - 1] === 0) {
        ans.pop();
    }

    // Ans is in the reversed order.
    // Reverse it to get the final ans.
    ans.reverse();
    return ans.join("");
}
```

</details>

<br>

## Approach 3: Sum the products from all pairs of digits

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* reverse(char* str) {
    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}
char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        return "0";
    }
    // Reverse num1 and num2.
    reverse(num1);
    reverse(num2);
    // Initialize answer as a string of zeros of length N.
    int N = strlen(num1) + strlen(num2);
    char* answer = (char*)calloc(N + 1, sizeof(char));
    memset(answer, '0', N);
    for (int place2 = 0; place2 < strlen(num2); place2++) {
        int digit2 = num2[place2] - '0';
        // For each digit in num2 multiply the digit by all digits in num1.
        for (int place1 = 0; place1 < strlen(num1); place1++) {
            int digit1 = num1[place1] - '0';
            // The number of zeros from multiplying two digits depends on the
            // place of digit2 in num2 and the place of the digit1 in num1.
            int numZeros = place1 + place2;
            // The digit currently at position numZeros in the answer string
            // is carried over and summed with the current result.
            int carry = answer[numZeros] - '0';
            int multiplication = digit1 * digit2 + carry;
            // Set the ones place of the multiplication result.
            answer[numZeros] = (multiplication % 10) + '0';
            // Carry the tens place of the multiplication result by
            // adding it to the next position in the answer array.
            answer[numZeros + 1] += (multiplication / 10);
        }
    }
    if (answer[N - 1] == '0') {
        answer[N - 1] = '\0';
    }
    reverse(answer);
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        // Reverse num1 and num2.
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // Initialize answer as a string of zeros of length N.
        int N = num1.size() + num2.size();
        string answer(N, '0');

        for (int place2 = 0; place2 < num2.size(); place2++) {
            int digit2 = num2[place2] - '0';

            // For each digit in num2 multiply the digit by all digits in num1.
            for (int place1 = 0; place1 < num1.size(); place1++) {
                int digit1 = num1[place1] - '0';

                // The number of zeros from multiplying to digits depends on the
                // place of digit2 in num2 and the place of the digit1 in num1.
                int numZeros = place1 + place2;

                // The digit currently at position numZeros in the answer string
                // is carried over and summed with the current result.
                int carry = answer[numZeros] - '0';
                int multiplication = digit1 * digit2 + carry;

                // Set the ones place of the multiplication result.
                answer[numZeros] = (multiplication % 10) + '0';

                // Carry the tens place of the multiplication result by
                // adding it to the next position in the answer array.
                answer[numZeros + 1] += (multiplication / 10);
            }
        }

        if (answer.back() == '0') {
            answer.pop_back();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string Multiply(string num1, string num2) {
        if (num1.Equals("0") || num2.Equals("0")) {
            return "0";
        }

        char[] firstNumber = num1.ToCharArray();
        char[] secondNumber = num2.ToCharArray();
        Array.Reverse(firstNumber);
        Array.Reverse(secondNumber);
        // To store the multiplication result of each digit of secondNumber with
        // firstNumber.
        int firstNumLength = firstNumber.Length;
        int secondNumLength = secondNumber.Length;
        int resultArrayLength = firstNumLength + secondNumLength;
        int[] resultArray = new int[resultArrayLength];
        for (int place2 = 0; place2 < secondNumLength; place2++) {
            int digit2 = secondNumber[place2] - '0';
            // For each digit in secondNumber multiply the digit by all digits
            // in firstNumber.
            for (int place1 = 0; place1 < firstNumLength; place1++) {
                int digit1 = firstNumber[place1] - '0';
                // The number of zeros from multiplying to digits depends on the
                // place of digit2 in secondNumber and the place of the digit1
                // in firstNumber.
                int numZeros = place1 + place2;
                int multiplication = digit1 * digit2 + resultArray[numZeros];
                // Set the ones place of the multiplication result.
                resultArray[numZeros] = multiplication % 10;
                // Carry the tens place of the multiplication result by
                // adding it to the next position in the answer array.
                resultArray[numZeros + 1] += multiplication / 10;
            }
        }

        // Pop excess 0s from the rear of answer.
        if (resultArray[resultArray.Length - 1] == 0) {
            resultArray = resultArray.Take(resultArray.Length - 1).ToArray();
        }

        // Ans is in the reversed order.
        // Reverse it to get the final ans.
        Array.Reverse(resultArray);
        return string.Join(
            string.Empty,
            resultArray.Select(digit => digit.ToString()).ToArray());
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
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
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        StringBuilder firstNumber = new StringBuilder(num1);
        StringBuilder secondNumber = new StringBuilder(num2);

        // Reverse both the numbers.
        firstNumber.reverse();
        secondNumber.reverse();

        // To store the multiplication result of each digit of secondNumber with firstNumber.
        int N = firstNumber.length() + secondNumber.length();
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < N; ++i) {
            answer.append(0);
        }

        for (int place2 = 0; place2 < secondNumber.length(); place2++) {
            int digit2 = secondNumber.charAt(place2) - '0';

            // For each digit in secondNumber multiply the digit by all digits in firstNumber.
            for (int place1 = 0; place1 < firstNumber.length(); place1++) {
                int digit1 = firstNumber.charAt(place1) - '0';

                // The number of zeros from multiplying to digits depends on the
                // place of digit2 in secondNumber and the place of the digit1 in firstNumber.
                int currentPos = place1 + place2;

                // The digit currently at position currentPos in the answer string
                // is carried over and summed with the current result.
                int carry = answer.charAt(currentPos) - '0';
                int multiplication = digit1 * digit2 + carry;

                // Set the ones place of the multiplication result.
                answer.setCharAt(
                    currentPos,
                    (char) ((multiplication % 10) + '0')
                );

                // Carry the tens place of the multiplication result by
                // adding it to the next position in the answer array.
                int value =
                    (answer.charAt(currentPos + 1) - '0') + multiplication / 10;
                answer.setCharAt(currentPos + 1, (char) (value + '0'));
            }
        }

        // Pop excess 0 from the rear of answer.
        if (answer.charAt(answer.length() - 1) == '0') {
            answer.deleteCharAt(answer.length() - 1);
        }

        answer.reverse();
        return answer.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let multiply = function (num1, num2) {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }

    let firstNumber = [...num1];
    let secondNumber = [...num2];

    // Reverse both the numbers.
    firstNumber.reverse();
    secondNumber.reverse();

    // To store the multiplication result of each digit of secondNumber with firstNumber.
    let N = firstNumber.length + secondNumber.length;
    let answer = new Array(N).fill(0);

    for (let place2 = 0; place2 < secondNumber.length; place2++) {
        let digit2 = Number(secondNumber[place2]);

        // For each digit in secondNumber multiply the digit by all digits in firstNumber.
        for (let place1 = 0; place1 < firstNumber.length; place1++) {
            let digit1 = Number(firstNumber[place1]);

            // The number of zeros from multiplying to digits depends on the
            // place of digit2 in secondNumber and the place of the digit1 in firstNumber.
            let currentPos = place1 + place2;

            // The digit currently at position currentPos in the answer string
            // is carried over and summed with the current result.
            let carry = answer[currentPos];
            let multiplication = digit1 * digit2 + carry;

            // Set the ones place of the multiplication result.
            answer[currentPos] = multiplication % 10;

            // Carry the tens place of the multiplication result by
            // adding it to the next position in the answer array.
            answer[currentPos + 1] += Math.floor(multiplication / 10);
        }
    }

    if (answer[answer.length - 1] == 0) {
        answer.pop();
    }

    // Ans is in the reversed order.
    // Reverse it to get the final ans.
    answer.reverse();
    return answer.join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        # Initialize answer as a string of zeros of length N.
        N = len(num1) + len(num2)
        answer = [0] * N

        # Reverse num1 and num2
        first_number = num1[::-1]
        second_number = num2[::-1]

        for place2, digit2 in enumerate(second_number):
            # For each digit in second_number multiply the digit by all digits in first_number.
            for place1, digit1 in enumerate(first_number):
                # The number of zeros from multiplying to digits depends on the place
                # of digit2 in second_number and the place of the digit1 in first_number.
                num_zeros = place1 + place2

                # The digit currently at position numZeros in the answer string
                # is carried over and summed with the current result.
                carry = answer[num_zeros]
                multiplication = int(digit1) * int(digit2) + carry

                # Set the ones place of the multiplication result.
                answer[num_zeros] = multiplication % 10

                # Carry the tens place of the multiplication result by
                # adding it to the next position in the answer array.
                answer[num_zeros + 1] += multiplication // 10

        # Pop the excess 0 from the end of answer.
        if answer[-1] == 0:
            answer.pop()

        return "".join(str(digit) for digit in reversed(answer))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function multiply(num1: string, num2: string): string {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }
    let firstNumber = [...num1];
    let secondNumber = [...num2];
    // Reverse both the numbers.
    firstNumber.reverse();
    secondNumber.reverse();
    // To store the multiplication result of each digit of secondNumber with firstNumber.
    let N = firstNumber.length + secondNumber.length;
    let answer = new Array(N).fill(0);
    for (let place2 = 0; place2 < secondNumber.length; place2++) {
        let digit2 = Number(secondNumber[place2]);
        // For each digit in secondNumber multiply the digit by all digits in firstNumber.
        for (let place1 = 0; place1 < firstNumber.length; place1++) {
            let digit1 = Number(firstNumber[place1]);
            // The number of zeros from multiplying two digits depends on the
            // place of digit2 in secondNumber and the place of the digit1 in firstNumber.
            let currentPos = place1 + place2;
            // The digit currently at position currentPos in the answer string
            // is carried over and summed with the current result.
            let carry = answer[currentPos];
            let multiplication = digit1 * digit2 + carry;
            // Set the ones place of the multiplication result.
            answer[currentPos] = multiplication % 10;
            // Carry the tens place of the multiplication result by
            // adding it to the next position in the answer array.
            answer[currentPos + 1] += Math.floor(multiplication / 10);
        }
    }
    // Pop excess 0s from the rear of answer.
    if (answer[answer.length - 1] == 0) {
        answer.pop();
    }
    // Ans is in the reversed order.
    // Reverse it to get the final ans.
    answer.reverse();
    return answer.join("");
}
```

</details>
