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
