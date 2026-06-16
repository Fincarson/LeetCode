int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    int num1 = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x == 1) {
            num1++;
        }
        g = gcd(g, x);
    }
    if (num1 > 0) {
        return n - num1;
    }
    if (g > 1) {
        return -1;
    }

    int min_len = n;
    for (int i = 0; i < n; i++) {
        int current_gcd = 0;
        for (int j = i; j < n; j++) {
            current_gcd = gcd(current_gcd, nums[j]);
            if (current_gcd == 1) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                }
                break;
            }
        }
    }
    return min_len + n - 2;
}
