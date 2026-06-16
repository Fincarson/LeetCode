public class Solution {
    private Dictionary<string, int> wordCount = new Dictionary<string, int>();
    private int wordLength;
    private int substringSize;
    private int k;

    private bool Check(int i, string s) {
        // Copy the original dictionary to use for this index
        var remaining = new Dictionary<string, int>(wordCount);
        int wordsUsed = 0;
        // Each iteration will check for a match in words
        for (int j = i; j < i + substringSize; j += wordLength) {
            string sub = s.Substring(j, wordLength);
            if (remaining.ContainsKey(sub) && remaining[sub] != 0) {
                remaining[sub] = remaining[sub] - 1;
                wordsUsed++;
            } else {
                break;
            }
        }

        return wordsUsed == k;
    }

    public IList<int> FindSubstring(string s, string[] words) {
        int n = s.Length;
        k = words.Length;
        wordLength = words[0].Length;
        substringSize = wordLength * k;
        foreach (var word in words)
            wordCount[word] =
                wordCount.ContainsKey(word) ? wordCount[word] + 1 : 1;
        IList<int> answer = new List<int>();
        for (int i = 0; i < n - substringSize + 1; i++) {
            if (Check(i, s)) {
                answer.Add(i);
            }
        }

        return answer;
    }
}
