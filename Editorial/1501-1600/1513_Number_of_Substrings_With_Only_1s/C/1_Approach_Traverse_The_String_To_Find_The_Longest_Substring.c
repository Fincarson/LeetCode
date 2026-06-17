int numSub(char* s) {
    const int MODULO = 1000000007;
    long total = 0;
    long consecutive = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') {
            total += consecutive * (consecutive + 1) / 2;
            total %= MODULO;
            consecutive = 0;
        } else {
            consecutive++;
        }
    }
    total += consecutive * (consecutive + 1) / 2;
    total %= MODULO;
    return (int)total;
}
