int f(int k) {
    if (k == 0) {
        return 1;
    }
    
    return 2 * f(k - 1) + 1;
}
