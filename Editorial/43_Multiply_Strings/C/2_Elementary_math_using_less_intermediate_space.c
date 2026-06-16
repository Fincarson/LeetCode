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
