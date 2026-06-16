public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> words = new HashSet<string>(wordDict);
        Queue<int> queue = new Queue<int>();
        bool[] seen = new bool[s.Length + 1];
        queue.Enqueue(0);
        while (queue.Count != 0) {
            int start = queue.Dequeue();
            if (start == s.Length) {
                return true;
            }

            for (int end = start + 1; end <= s.Length; end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.Contains(s.Substring(start, end - start))) {
                    queue.Enqueue(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
}
