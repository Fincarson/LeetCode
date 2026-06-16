public class Solution {
    public int MinDistance(string word1, string word2) {
        int?[][] memo = new int ?[word1.Length + 1][];
        for (int i = 0; i <= word1.Length; i++)
            memo[i] = new int?[word2.Length + 1];
        return MinDistanceRecur(word1, word2, word1.Length, word2.Length);

        int MinDistanceRecur(string word1, string word2, int word1Index,
                             int word2Index) {
            if (word1Index == 0)
                return word2Index;
            if (word2Index == 0)
                return word1Index;
            if (memo[word1Index][word2Index] != null)
                return memo[word1Index][word2Index].Value;
            int minEditDistance = 0;
            if (word1[word1Index - 1] == word2[word2Index - 1])
                minEditDistance = MinDistanceRecur(word1, word2, word1Index - 1,
                                                   word2Index - 1);
            else {
                int insertOperation =
                    MinDistanceRecur(word1, word2, word1Index, word2Index - 1);
                int deleteOperation =
                    MinDistanceRecur(word1, word2, word1Index - 1, word2Index);
                int replaceOperation = MinDistanceRecur(
                    word1, word2, word1Index - 1, word2Index - 1);
                minEditDistance =
                    Math.Min(insertOperation,
                             Math.Min(deleteOperation, replaceOperation)) +
                    1;
            }

            memo[word1Index][word2Index] = minEditDistance;
            return minEditDistance;
        }
    }
}
