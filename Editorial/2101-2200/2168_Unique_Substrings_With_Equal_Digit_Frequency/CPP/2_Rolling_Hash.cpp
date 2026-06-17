class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        int prime = 31;            // Prime base for the rolling hash
        long long int mod = 10e9;  // Large prime modulus to avoid overflow
        unordered_set<long long int> validSubstringHashes;

        for (int start = 0; start < n; start++) {
            vector<int> digitFrequency(10, 0);
            // Track number of unique digits in the substring
            int uniqueDigitsCount = 0;
            // Rolling hash for the current substring
            long long int substringHash = 0;
            // Maximum frequency of any digit in the substring
            int maxDigitFrequency = 0;

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                int currentDigit = s[end] - '0';

                // If this digit appears for the first time, increment
                // uniqueDigits
                if (digitFrequency[currentDigit] == 0) {
                    uniqueDigitsCount++;
                }

                digitFrequency[currentDigit]++;
                maxDigitFrequency =
                    max(maxDigitFrequency, digitFrequency[currentDigit]);

                // Update rolling hash
                substringHash =
                    (prime * substringHash + currentDigit + 1) % mod;

                // Check if all digits in the substring have the same frequency
                if (maxDigitFrequency * uniqueDigitsCount == end - start + 1) {
                    // Insert unique hash
                    validSubstringHashes.insert(substringHash);
                }
            }
        }

        return validSubstringHashes.size();
    }
};
