char* convertToTitle(int columnNumber) {
    char* ans = calloc(1020, sizeof(char));
    int i = 0;
    while (columnNumber > 0) {
        columnNumber--;
        // Get the last character and append it at the end of string.
        ans[i++] = columnNumber % 26 + 'A';
        columnNumber = columnNumber / 26;
    }

    // Reverse it, as we appended characters in reverse order.
    int head = 0, tail = i - 1;
    while (head < tail) {
        char temp = ans[head];
        ans[head] = ans[tail];
        ans[tail] = temp;
        head++;
        tail--;
    }
    return ans;
}
