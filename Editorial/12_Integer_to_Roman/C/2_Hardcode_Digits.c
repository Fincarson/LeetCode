char *intToRoman(int num) {
    const char *thousands[] = {"", "M", "MM", "MMM"};
    const char *hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
                              "D", "DC", "DCC", "DCCC", "CM"};
    const char *tens[] = {"",  "X",  "XX",  "XXX",  "XL",
                          "L", "LX", "LXX", "LXXX", "XC"};
    const char *ones[] = {"",  "I",  "II",  "III",  "IV",
                          "V", "VI", "VII", "VIII", "IX"};

    char *result = (char *)malloc(16 * sizeof(char));
    strcpy(result, "");

    strcat(result, thousands[num / 1000]);
    strcat(result, hundreds[num % 1000 / 100]);
    strcat(result, tens[num % 100 / 10]);
    strcat(result, ones[num % 10]);

    return result;
}
