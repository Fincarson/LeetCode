class Solution {
public:
    string shortestPalindrome(string s) {
        long long hashBase = 29;
        long long modValue = 1e9 + 7;
        long long forwardHash = 0, reverseHash = 0, powerValue = 1;
        int palindromeEndIndex = -1;

        // Calculate rolling hashes and find the longest palindromic prefix
        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];

            // Update forward hash
            forwardHash =
                (forwardHash * hashBase + (currentChar - 'a' + 1)) % modValue;

            // Update reverse hash
            reverseHash =
                (reverseHash + (currentChar - 'a' + 1) * powerValue) % modValue;
            powerValue = (powerValue * hashBase) % modValue;

            // If forward and reverse hashes match, update palindrome end index
            if (forwardHash == reverseHash) {
                palindromeEndIndex = i;
            }
        }

        // Find the remaining suffix after the longest palindromic prefix
        string suffix = s.substr(palindromeEndIndex + 1);
        // Reverse the remaining suffix
        string reversedSuffix(suffix.rbegin(), suffix.rend());

        // Prepend the reversed suffix to the original string and return the
        // result
        return reversedSuffix + s;
    }
};
