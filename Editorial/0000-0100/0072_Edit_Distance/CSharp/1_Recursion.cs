public class Solution {
    public int MinDistance(string word1, string word2) {
        return MinDistanceRecur(word1, word2, word1.Length, word2.Length);
    }

    public int MinDistanceRecur(string word1, string word2, int word1Index,
                                int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }

        if (word2Index == 0) {
            return word1Index;
        }

        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            return MinDistanceRecur(word1, word2, word1Index - 1,
                                    word2Index - 1);
        } else {
            int insertOperation =
                MinDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation =
                MinDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation =
                MinDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            return Math.Min(insertOperation,
                            Math.Min(deleteOperation, replaceOperation)) +
                   1;
        }
    }
}
