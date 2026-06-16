int myAtoi(char* s) {
    long sign = 1;
    long result = 0;
    int i = 0;

    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '+') {
        sign = 1;
        i++;
    } else if (s[i] == '-') {
        sign = -1;
        i++;
    }

    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }

    return sign * result;
}
