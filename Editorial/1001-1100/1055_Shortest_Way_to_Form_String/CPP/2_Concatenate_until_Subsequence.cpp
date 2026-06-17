class Solution {
public:
    int shortestWay(string source, string target) {

        // Boolean array to mark all characters of the source
        bool sourceChars[26] = {false};
        for (char c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of the target are present in the source
        // If any character is not present, return -1
        for (char c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Concatenate source until the target is a subsequence of the concatenated string
        string concatenatedSource = source;
        int count = 1;
        while (!isSubsequence(target, concatenatedSource)) {
            concatenatedSource += source;
            count++;
        }

        // Number of concatenations done
        return count;
    }

    // To check if toCheck is a subsequence of inString
    bool isSubsequence(string toCheck, string inString) {
        int i = 0, j = 0;
        while (i < toCheck.length() && j < inString.length()) {
            if (toCheck[i] == inString[j]) {
                i++;
            }
            j++;
        }

        return i == toCheck.length();
    }
};
