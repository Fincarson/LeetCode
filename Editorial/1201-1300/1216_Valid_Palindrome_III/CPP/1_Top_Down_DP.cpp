class Solution {
public:
    vector<vector<int>> memo;
    int isValidPalindrome(string &s, int i, int j) {

        // Base case, only 1 letter remaining.
        if (i == j)
            return 0;

        // Base case 2, only 2 letters remaining.
        if (i == j - 1)
            return s[i] != s[j];

        // Return the precomputed value if exists.
        if (memo[i][j] != -1)
            return memo[i][j];

        // Case 1: Character at `i` equals character at `j`
        if (s[i] == s[j])
            return memo[i][j] = isValidPalindrome(s, i + 1, j - 1);

        // Case 2: Character at `i` does not equal character at `j`.
        // Either delete character at `i` or delete character at `j`
        // and try to match the two pointers using recursion.
        // We need to take the minimum of the two results and add 1
        // representing the cost of deletion.
        return memo[i][j] = 1 + min(isValidPalindrome(s, i + 1, j), isValidPalindrome(s, i, j - 1));
    }
    bool isValidPalindrome(string s, int k) {
        memo.resize(s.length(), vector<int>(s.length(), -1));

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return isValidPalindrome(s, 0, s.length() - 1) <= k;
    }
};
