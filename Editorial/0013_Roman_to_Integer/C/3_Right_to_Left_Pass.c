struct roman_value {
    char letter;
    int value;
};

const struct roman_value values[] = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int find_value(char letter) {
    for (int i = 0; i < sizeof(values) / sizeof(*values); ++i) {
        if (values[i].letter == letter) {
            return values[i].value;
        }
    }
    return 0;
}

int romanToInt(char* s) {
    int total = find_value(s[strlen(s) - 1]);
    for (int i = strlen(s) - 2; i >= 0; --i) {
        if (find_value(s[i]) < find_value(s[i + 1])) {
            total -= find_value(s[i]);
        } else {
            total += find_value(s[i]);
        }
    }
    return total;
}
