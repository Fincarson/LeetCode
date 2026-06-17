int getWaviness(int x) {
    char s[12];
    sprintf(s, "%d", x);
    int waviness = 0;
    int len = strlen(s);

    for (int i = 1; i < len - 1; i++) {
        int isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
        int isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
        if (isPeak || isValley) {
            waviness++;
        }
    }

    return waviness;
}

int totalWaviness(int num1, int num2) {
    int total = 0;
    for (int i = num1; i <= num2; i++) {
        total += getWaviness(i);
    }
    return total;
}
