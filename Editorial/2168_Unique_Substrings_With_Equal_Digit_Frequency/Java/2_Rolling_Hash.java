class Solution {

    public int equalDigitFrequency(String s) {
        int n = s.length();
        int prime = 31; // Prime base for the rolling hash
        long mod = 1000000000L;
        Set<Long> validSubstringHashes = new HashSet<>();

        for (int start = 0; start < n; start++) {
            int[] digitFrequency = new int[10]; // Frequency array for digits 0-9
            int uniqueDigitsCount = 0; // Track number of unique digits in the substring
            long substringHash = 0; // Rolling hash for the current substring
            int maxDigitFrequency = 0; // Maximum frequency of any digit in the substring

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                int currentDigit = s.charAt(end) - '0';

                // This digit appears for the first time
                if (digitFrequency[currentDigit] == 0) {
                    uniqueDigitsCount++;
                }

                digitFrequency[currentDigit]++;
                maxDigitFrequency = Math.max(
                    maxDigitFrequency,
                    digitFrequency[currentDigit]
                );

                // Update rolling hash
                substringHash =
                    (prime * substringHash + currentDigit + 1) % mod;

                // Check if all digits in the substring have the same frequency
                if (maxDigitFrequency * uniqueDigitsCount == end - start + 1) {
                    validSubstringHashes.add(substringHash); // Insert unique hash
                }
            }
        }

        return validSubstringHashes.size();
    }
}
