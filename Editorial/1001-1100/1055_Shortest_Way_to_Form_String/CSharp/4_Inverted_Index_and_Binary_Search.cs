class Solution {
    public int ShortestWay(string source, string target) {

        // List of indices for all characters in source
        List < int > [] charToIndices = new List < int > [26];
        for (int i = 0; i < source.Length; i++) {
            char c = source[i];
            if (charToIndices[c - 'a'] == null) {
                charToIndices[c - 'a'] = new List < int > ();
            }
            charToIndices[c - 'a'].Add(i);
        }

        // Pointer for source
        int sourceIterator = 0;

        // Number of times we need to iterate through source
        int count = 1;

        // Find all characters of target in source
        foreach (char c in target) {

            // If the character is not in the source, return -1
            if (charToIndices[c - 'a'] == null) {
                return -1;
            }

            // Binary search to find the index of the character in source
            // next to the source iterator
            List < int > indices = charToIndices[c - 'a'];
            int index = indices.BinarySearch(sourceIterator);

            // If the index is negative, we need to find the next index
            // that is greater than the source iterator
            if (index < 0) {
                index = ~index;
            }

            // If we have reached the end of the list, we need to iterate
            // through source again, hence first index of character in source.
            if (index == indices.Count) {
                count++;
                sourceIterator = indices[0] + 1;
            } else {
                sourceIterator = indices[index] + 1;
            }
        }

        // Return the number of times we need to iterate through source
        return count;
    }
}
