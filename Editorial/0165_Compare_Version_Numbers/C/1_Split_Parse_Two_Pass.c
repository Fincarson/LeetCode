int compareVersion(char* version1, char* version2) {
    while (*version1 || *version2) {
        long num1 = strtol(version1, &version1, 10);
        long num2 = strtol(version2, &version2, 10);

        if (num1 > num2) return 1;
        if (num1 < num2) return -1;

        if (*version1) version1++;
        if (*version2) version2++;
    }

    return 0;
}
