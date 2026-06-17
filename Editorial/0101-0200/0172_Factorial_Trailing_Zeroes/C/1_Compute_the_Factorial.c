#define MAX_DIGITS 50000  // Adjust as needed based on expected factorial size

typedef struct {
    int digits[MAX_DIGITS];
    int size;
} BigInt;

// Initializes a BigInt from an integer
void BigInt_init(BigInt *bi, int value) {
    memset(bi->digits, 0, sizeof(bi->digits));
    bi->size = 0;
    if (value == 0) {
        bi->digits[0] = 0;
        bi->size = 1;
        return;
    }
    while (value > 0) {
        bi->digits[bi->size++] = value % 10;
        value /= 10;
    }
}

// Multiplies BigInt by an integer
void BigInt_multiply(BigInt *bi, int value) {
    int carry = 0;
    for (int i = 0; i < bi->size; i++) {
        int product = bi->digits[i] * value + carry;
        bi->digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        bi->digits[bi->size++] = carry % 10;
        carry /= 10;
    }
}

// Divides BigInt by 10 and returns the remainder
int BigInt_divide_by_10(BigInt *bi) {
    int remainder = 0;
    for (int i = bi->size - 1; i >= 0; i--) {
        int current = remainder * 10 + bi->digits[i];
        bi->digits[i] = current / 10;
        remainder = current % 10;
    }
    if (bi->size > 1 && bi->digits[bi->size - 1] == 0) {
        bi->size--;
    }
    return remainder;
}

int trailingZeroes(int n) {
    BigInt factorial;
    BigInt_init(&factorial, 1);
    for (int i = 2; i <= n; i++) {
        BigInt_multiply(&factorial, i);
    }

    int zeroCount = 0;
    while (BigInt_divide_by_10(&factorial) == 0) {
        zeroCount++;
    }
    return zeroCount;
}
