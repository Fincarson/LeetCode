class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int length = s.length();
        vector<string> suffixes(length);

        // Create suffix array by storing all suffixes of the string
        for (int i = 0; i < length; i++) {
            suffixes[i] = s.substr(i);
        }
        // Sort the suffix array using MSD Radix Sort
        msdRadixSort(suffixes);

        int maxLength = 0;
        // Compare adjacent suffixes to find the longest common prefix
        for (int i = 1; i < length; i++) {
            int j = 0;
            // Compare characters one by one until they differ or end of one
            // suffix is reached
            while (j < min(suffixes[i].length(), suffixes[i - 1].length()) &&
                   suffixes[i][j] == suffixes[i - 1][j]) {
                j++;
            }
            // Update maxLength with the length of the common prefix
            maxLength = max(maxLength, j);
        }
        return maxLength;  // Return the maximum length of repeating substring
                           // found
    }

private:
    void msdRadixSort(vector<string>& input) {
        vector<string> aux(input.size());
        sort(input, 0, input.size() - 1, 0, aux);
    }

    void sort(vector<string>& input, int lo, int hi, int depth,
              vector<string>& aux) {
        if (lo >= hi) return;

        vector<int> count(28, 0);
        // Count frequencies of each character at the current depth
        for (int i = lo; i <= hi; i++) {
            count[charAt(input[i], depth) + 1]++;
        }
        // Compute cumulates which give positions of each character
        for (int i = 1; i < 28; i++) {
            count[i] += count[i - 1];
        }
        // Move items to auxiliary array based on cumulates
        for (int i = lo; i <= hi; i++) {
            aux[count[charAt(input[i], depth)]++] = input[i];
        }
        // Copy back to original array
        for (int i = lo; i <= hi; i++) {
            input[i] = aux[i - lo];
        }
        // Recursively sort for each character value
        for (int i = 0; i < 27; i++) {
            sort(input, lo + count[i], lo + count[i + 1] - 1, depth + 1, aux);
        }
    }

    // Returns the character value or 0 if index exceeds string length
    int charAt(const string& s, int index) {
        if (index >= s.length()) return 0;
        return s[index] - 'a' + 1;
    }
};
