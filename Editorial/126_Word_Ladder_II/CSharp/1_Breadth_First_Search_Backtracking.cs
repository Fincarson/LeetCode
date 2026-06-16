public class Solution {
    Dictionary<string, List<string>> adjList =
        new Dictionary<string, List<string>>();

    List<string> currPath = new List<string>();
    List<IList<string>> shortestPaths = new List<IList<string>>();

    private List<string> FindNeighbors(string word, HashSet<string> wordList) {
        List<string> neighbors = new List<string>();
        char[] charList = word.ToCharArray();
        for (int i = 0; i < word.Length; i++) {
            char oldChar = charList[i];

            // replace the i-th character with all letters from a to z except
            // the original character
            for (char c = 'a'; c <= 'z'; c++) {
                charList[i] = c;

                // skip if the character is same as original or if the word is
                // not present in the wordList
                if (c == oldChar ||
                    !wordList.Contains(string.Join("", charList))) {
                    continue;
                }

                neighbors.Add(string.Join("", charList));
            }

            charList[i] = oldChar;
        }

        return neighbors;
    }

    private void Backtrack(string source, string destination) {
        // store the path if we reached the endWord
        if (source.Equals(destination)) {
            List<string> tempPath = new List<string>(currPath);
            tempPath.Reverse();
            shortestPaths.Add(tempPath);
        }

        if (!adjList.ContainsKey(source)) {
            return;
        }

        for (int i = 0; i < adjList[source].Count; i++) {
            currPath.Add(adjList[source][i]);
            Backtrack(adjList[source][i], destination);
            currPath.RemoveAt(currPath.Count - 1);
        }
    }

    private void bfs(string beginWord, string endWord,
                     HashSet<string> wordList) {
        Queue<string> q = new Queue<string>();
        q.Enqueue(beginWord);

        // remove the root word which is the first layer in the BFS
        if (wordList.Contains(beginWord)) {
            wordList.Remove(beginWord);
        }

        Dictionary<string, int> isEnqueued = new Dictionary<string, int>();
        isEnqueued[beginWord] = 1;

        while (q.Count > 0) {
            List<string> visited = new List<string>();
            for (int i = q.Count - 1; i >= 0; i--) {
                string currWord = q.Peek();
                q.Dequeue();

                // findNeighbors will have the adjacent words of the currWord
                List<string> neighbors = FindNeighbors(currWord, wordList);
                foreach (string word in neighbors) {
                    visited.Add(word);
                    if (!adjList.ContainsKey(word)) {
                        adjList[word] = new List<string>();
                    }

                    // add the edge from word to currWord in the list
                    adjList[word].Add(currWord);
                    if (!isEnqueued.ContainsKey(word)) {
                        q.Enqueue(word);
                        isEnqueued[word] = 1;
                    }
                }
            }

            // removing the words of the previous layer
            for (int i = 0; i < visited.Count; i++) {
                if (wordList.Contains(visited[i])) {
                    wordList.Remove(visited[i]);
                }
            }
        }
    }

    public IList<IList<string>> FindLadders(string beginWord, string endWord,
                                            IList<string> wordList) {
        // copying the words into the set for efficient deletion in BFS
        HashSet<string> copiedWordList = new HashSet<string>(wordList);
        bfs(beginWord, endWord, copiedWordList);

        // every path will start from the endWord
        currPath.Add(endWord);
        // traverse the DAG to find all the paths between endWord and beginWord
        Backtrack(endWord, beginWord);

        return shortestPaths;
    }
}
