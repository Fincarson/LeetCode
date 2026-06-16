char *intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};
    char *roman = (char *)malloc(20 * sizeof(char));
    roman[0] = '\0';

    // Loop through each symbol, stopping if num becomes 0.
    for (int i = 0; i < 13 && num > 0; i++) {
        // Repeat while the current symbol still fits into num.
        while (values[i] <= num) {
            num -= values[i];
            strcat(roman, symbols[i]);
        }
    }
    return roman;
}
