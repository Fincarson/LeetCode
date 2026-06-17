public class Solution {
    Dictionary<string, List<string>> adjList =
        new Dictionary<string, List<string>>();

    List<string> currPath = new List<string>();
    List<List<string>> shortestPaths = new List<List<string>>();

    private List<string> findNeighbors(string word, HashSet<string> wordList) {
        List<string> neighbors = new List<string>();
        char[] charList = word.ToCharArray();
        for (int i = 0; i < word.Length; i++) {
            char oldChar = charList[i];
            for (char c = 'a'; c <= 'z'; c++) {
                charList[i] = c;
                if (c == oldChar || !wordList.Contains(new String(charList))) {
                    continue;
                }

                neighbors.Add(new String(charList));
            }

            charList[i] = oldChar;
        }

        return neighbors;
    }

    private void backtrack(string source, string destination) {
        if (source.Equals(destination)) {
            List<string> tempPath = new List<string>(currPath);
            shortestPaths.Add(tempPath);
        }

        if (!adjList.ContainsKey(source)) {
            return;
        }

        for (int i = 0; i < adjList[source].Count; i++) {
            currPath.Add(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.RemoveAt(currPath.Count - 1);
        }
    }

    private void addEdge(string word1, string word2, int direction) {
        if (direction == 1) {
            if (!adjList.ContainsKey(word1)) {
                adjList[word1] = new List<string>();
            }

            adjList[word1].Add(word2);
        } else {
            if (!adjList.ContainsKey(word2)) {
                adjList[word2] = new List<string>();
            }

            adjList[word2].Add(word1);
        }
    }

    private bool bfs(string beginWord, string endWord,
                     HashSet<string> wordList) {
        if (!wordList.Contains(endWord)) {
            return false;
        }

        if (wordList.Contains(beginWord)) {
            wordList.Remove(beginWord);
        }

        HashSet<string> forwardQueue = new HashSet<string>();
        HashSet<string> backwardQueue = new HashSet<string>();
        forwardQueue.Add(beginWord);
        backwardQueue.Add(endWord);
        bool found = false;
        int direction = 1;
        while (forwardQueue.Count != 0) {
            HashSet<string> visited = new HashSet<string>();
            if (forwardQueue.Count > backwardQueue.Count) {
                HashSet<string> temp = forwardQueue;
                forwardQueue = backwardQueue;
                backwardQueue = temp;
                direction ^= 1;
            }

            foreach (string currWord in forwardQueue) {
                List<string> neighbors = findNeighbors(currWord, wordList);
                foreach (string word in neighbors) {
                    if (backwardQueue.Contains(word)) {
                        found = true;
                        addEdge(currWord, word, direction);
                    } else if (!found && wordList.Contains(word) &&
                               !forwardQueue.Contains(word)) {
                        visited.Add(word);
                        addEdge(currWord, word, direction);
                    }
                }
            }

            foreach (string currWord in forwardQueue) {
                if (wordList.Contains(currWord)) {
                    wordList.Remove(currWord);
                }
            }

            if (found) {
                break;
            }

            forwardQueue = visited;
        }

        return found;
    }

    public IList<IList<string>> FindLadders(string beginWord, string endWord,
                                            IList<string> wordList) {
        HashSet<string> copiedWordList = new HashSet<string>(wordList);
        bool sequence_found = bfs(beginWord, endWord, copiedWordList);
        if (sequence_found == false) {
            return shortestPaths.ToArray();
        }

        currPath.Add(beginWord);
        backtrack(beginWord, endWord);
        return shortestPaths.ToArray();
    }
}
