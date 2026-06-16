public class Solution {
    int L;
    Dictionary<string, List<string>> allComboDict;
    Queue<Tuple<string, int>> Q_begin;
    Queue<Tuple<string, int>> Q_end;
    Dictionary<string, int> visitedBegin;
    Dictionary<string, int> visitedEnd;

    private int visitWordNode(Queue<Tuple<string, int>> Q,
                              Dictionary<string, int> visited,
                              Dictionary<string, int> othersVisited) {
        int x = Q.Count;
        while (x > 0) {
            var node = Q.Dequeue();
            string word = node.Item1;
            int level = node.Item2;
            for (int i = 0; i < L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, L - i - 1);
                if (this.allComboDict.ContainsKey(newWord)) {
                    foreach (string adjacentWord in this
                                 .allComboDict[newWord]) {
                        if (othersVisited.ContainsKey(adjacentWord)) {
                            return level + othersVisited[adjacentWord];
                        }

                        if (!visited.ContainsKey(adjacentWord)) {
                            visited.Add(adjacentWord, level + 1);
                            Q.Enqueue(new Tuple<string, int>(adjacentWord,
                                                             level + 1));
                        }
                    }
                }
            }

            x--;
        }

        return -1;
    }

    public int LadderLength(string beginWord, string endWord,
                            IList<string> wordList) {
        if (!wordList.Contains(endWord)) {
            return 0;
        }

        this.L = beginWord.Length;
        this.allComboDict = new Dictionary<string, List<string>>();
        foreach (string word in wordList) {
            for (int i = 0; i < this.L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, this.L - i - 1);
                if (this.allComboDict.ContainsKey(newWord)) {
                    this.allComboDict[newWord].Add(word);
                } else {
                    List<string> tempList = new List<string>();
                    tempList.Add(word);
                    this.allComboDict.Add(newWord, tempList);
                }
            }
        }

        this.Q_begin = new Queue<Tuple<string, int>>();
        this.Q_begin.Enqueue(new Tuple<string, int>(beginWord, 1));
        this.Q_end = new Queue<Tuple<string, int>>();
        this.Q_end.Enqueue(new Tuple<string, int>(endWord, 1));
        this.visitedBegin = new Dictionary<string, int> { { beginWord, 1 } };
        this.visitedEnd = new Dictionary<string, int> { { endWord, 1 } };
        while (this.Q_begin.Count != 0 && this.Q_end.Count != 0) {
            int ans = -1;
            if (this.Q_begin.Count <= this.Q_end.Count) {
                ans = this.visitWordNode(this.Q_begin, this.visitedBegin,
                                         this.visitedEnd);
            } else {
                ans = this.visitWordNode(this.Q_end, this.visitedEnd,
                                         this.visitedBegin);
            }

            if (ans > -1) {
                return ans;
            }
        }

        return 0;
    }
}
