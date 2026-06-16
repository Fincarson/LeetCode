class BigInt {
private:
    vector<int> digits;  // digits are stored in reverse order
    bool isNegative;

public:
    BigInt(long long num = 0) : isNegative(num < 0) {
        num = std::abs(num);
        if (num == 0) digits.push_back(0);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // Multiply this BigInt by an integer
    BigInt operator*(int num) const {
        if (num == 0) return BigInt(0);

        vector<int> result(digits.size() + 10, 0);
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            long long product = long(digits[i]) * num + carry;
            result[i] = product % 10;
            carry = product / 10;
        }

        for (size_t i = digits.size(); carry != 0; ++i) {
            result[i] = carry % 10;
            carry /= 10;
        }

        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }

        BigInt output;
        output.digits = std::move(result);
        return output;
    }

    // Divide this BigInt by an integer and return the quotient
    BigInt operator/(int divisor) const {
        BigInt result;
        result.digits.clear();
        int idx = digits.size() - 1;
        int rem = 0;
        while (idx >= 0) {
            rem = rem * 10 + digits[idx--];
            if (rem < divisor && !result.digits.empty()) {
                result.digits.push_back(0);
            } else if (rem >= divisor) {
                result.digits.push_back(rem / divisor);
                rem %= divisor;
            }
        }

        std::reverse(result.digits.begin(), result.digits.end());
        if (result.digits.empty()) result.digits.push_back(0);
        return result;
    }

    // Modulo operation with an integer
    int operator%(int divisor) const {
        int remainder = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            remainder = (remainder * 10 + digits[i]) % divisor;
        }
        return remainder;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        BigInt factorial = 1;
        for (int i = 2; i <= n; ++i) {
            factorial = factorial * i;
        }

        int zeroCount = 0;
        while (factorial % 10 == 0) {
            factorial = factorial / 10;
            zeroCount++;
        }

        return zeroCount;
    }
};
