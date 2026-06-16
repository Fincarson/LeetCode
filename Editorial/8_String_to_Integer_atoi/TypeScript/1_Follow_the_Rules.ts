function myAtoi(s: string): number {
    let sign = 1;
    let result = 0;
    let index = 0;
    let n = s.length;

    let INT_MAX = Math.pow(2, 31) - 1;
    let INT_MIN = -Math.pow(2, 31);

    while (index < n && s[index] == " ") {
        index++;
    }

    if (index < n && s[index] == "+") {
        sign = 1;
        index++;
    } else if (index < n && s[index] == "-") {
        sign = -1;
        index++;
    }

    while (index < n && s[index] >= "0" && s[index] <= "9") {
        let digit = Number(s[index]);

        if (
            result > Math.floor(INT_MAX / 10) ||
            (result == Math.floor(INT_MAX / 10) && digit > INT_MAX % 10)
        ) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = 10 * result + digit;
        index++;
    }

    return sign * result;
}
