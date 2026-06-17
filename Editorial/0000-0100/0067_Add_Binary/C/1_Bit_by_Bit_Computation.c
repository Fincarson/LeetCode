// Function to reverse a string in place
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to add two binary strings
char *addBinary(const char *a, const char *b) {
    int n = strlen(a);
    int m = strlen(b);
    if (n < m) {
        // Ensure 'a' is always the longer string
        return addBinary(b, a);
    }

    // Allocate memory for the result
    char *result = malloc(n + 2);  // +2 for possible carry and null terminator
    if (!result) return NULL;

    int carry = 0, j = m - 1;
    int pos = 0;  // Position to place the next char in result

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '1') ++carry;
        if (j >= 0 && b[j--] == '1') ++carry;

        result[pos++] =
            (carry % 2) ? '1' : '0';  // Append '1' or '0' based on carry
        carry /= 2;  // Reduce or maintain carry for the next bit addition
    }

    if (carry) {
        result[pos++] = '1';  // If there's still a carry, add a '1' at the end
    }
    result[pos] = '\0';  // Null-terminate the result string

    // Since we built the result in reverse order, reverse it before returning
    reverse(result);
    // Adjust the pointer to skip any extra leading zero
    if (result[0] == '0' && result[1] != '\0') {
        char *adjusted_result = strdup(result + 1);
        free(result);
        return adjusted_result;
    }

    return result;
}
