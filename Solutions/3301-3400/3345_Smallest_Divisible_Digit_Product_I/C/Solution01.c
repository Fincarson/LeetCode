int smallestNumber(int n, int t) {
    int digit1 = 0, digit0 = 0;
    while(1){
        digit1 = n  >= 100 ? n / 100 : n >= 10 ? n / 10 : 1;
        digit0 = n % 10;
        if ((digit1 * digit0) % t == 0) return n;
        n++;
    }
    return 0;
}