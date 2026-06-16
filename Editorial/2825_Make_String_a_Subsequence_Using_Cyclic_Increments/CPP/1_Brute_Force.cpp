class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int lengthStr1 = str1.length();

        // Try all possible combinations of character increments
        for (int mask = 0; mask < (1 << lengthStr1); mask++) {
            string temp = str1;

            // Apply increments based on current mask
            for (int str1Index = 0; str1Index < lengthStr1; str1Index++) {
                if (mask & (1 << str1Index)) {
                    temp[str1Index] = getNextChar(temp[str1Index]);
                }
            }

            // Check if str2 is a subsequence of the modified string
            if (isSubsequence(temp, str2)) {
                return true;
            }
        }

        return false;
    }

private:
    // Helper function to get the next character cyclically
    char getNextChar(char str1Char) {
        return str1Char == 'z' ? 'a' : str1Char + 1;
    }

    // Helper function to check if str2 is a subsequence of str1
    bool isSubsequence(string& str1, string& str2) {
        int str1Index = 0, str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        // Traverse through both strings using a while loop
        while (str1Index < lengthStr1 && str2Index < lengthStr2) {
            if (str1[str1Index] == str2[str2Index]) {
                str2Index++;
            }
            str1Index++;
        }
        // Check if all characters in str2 were matched
        return str2Index == lengthStr2;
    }
};
