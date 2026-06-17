class Solution {
    public int ShortestWay(string source, string target) {

        // Boolean array to mark all characters of source
        bool[] sourceChars = new bool[26];
        foreach (char c in source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        foreach (char c in target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Concatenate source until target is a subsequence of concatenated string
        string concatenatedSource = source;
        int count = 1;
        while (!IsSubsequence(target, concatenatedSource)) {
            concatenatedSource += source;
            count++;
        }

        // Number of concatenations done
        return count;
    }

    // To check if toCheck is a subsequence of inString
    bool IsSubsequence(string toCheck, string inString) {
        int i = 0, j = 0;
        while (i < toCheck.Length && j < inString.Length) {
            if (toCheck[i] == inString[j]) {
                i++;
            }
            j++;
        }

        return i == toCheck.Length;
    }
}
