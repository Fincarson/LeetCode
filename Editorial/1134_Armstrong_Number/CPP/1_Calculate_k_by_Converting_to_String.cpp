class Solution {
public:
    int getSumOfKthPowerOfDigits(int n, int k) {
       // `result` stores the result of sum of k'th power of each digit.
       int result = 0;

       // Run until n is not 0
       while (n != 0) {
           // Modulo 10 gives us the last digit
           // Add digit ^ k to the result
           result += pow(n % 10, k);

           // Remove the last digit.
           n /= 10;
       }
       return result;
    }
    bool isArmstrong(int n) {
        // Get length of the number by converting to string.
        int length = to_string(n).length();

        // Return true if Sum of k'th power of digits equals original number.
        return getSumOfKthPowerOfDigits(n, length) == n;
    }
};
