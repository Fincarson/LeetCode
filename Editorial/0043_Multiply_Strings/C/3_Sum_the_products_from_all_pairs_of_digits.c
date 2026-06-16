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
