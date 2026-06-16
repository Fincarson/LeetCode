func findLadders(
    beginWord string,
    endWord string,
    wordList []string,
) [][]string {
    adjList := make(map[string][]string)
    var currPath []string
    var shortestPaths [][]string

    wordSet := make(map[string]bool)
    // copying the words into the set for efficient deletion in BFS
    for _, word := range wordList {
        wordSet[word] = true
    }
    // build the DAG using BFS
    bfs(beginWord, endWord, wordSet, adjList)

    // every path will start from the endWord
    currPath = append(currPath, endWord)
    // traverse the DAG to find all the paths between endWord and beginWord
    backtrack(endWord, beginWord, &currPath, &shortestPaths, adjList)

    return shortestPaths
}

func findNeighbors(word string, wordSet map[string]bool) []string {
    var neighbors []string
    charList := []rune(word)
    for i := range charList {
        oldChar := charList[i]
        // replace the i-th character with all letters from a to z except the original character
        for c := 'a'; c <= 'z'; c++ {
            charList[i] = c
            newWord := string(charList)
            // skip if the character is same as original or if the word is not present in the wordSet
            if c == oldChar || !wordSet[newWord] {
                continue
            }
            neighbors = append(neighbors, newWord)
        }
        charList[i] = oldChar
    }
    return neighbors
}

func backtrack(
    source string,
    destination string,
    currPath *[]string,
    shortestPaths *[][]string,
    adjList map[string][]string,
) {
    // store the path if we reached the endWord
    if source == destination {
        tempPath := make([]string, len(*currPath))
        copy(tempPath, *currPath)
        for i, j := 0, len(tempPath)-1; i < j; i, j = i+1, j-1 {
            tempPath[i], tempPath[j] = tempPath[j], tempPath[i]
        }
        *shortestPaths = append(*shortestPaths, tempPath)
    }

    if neighbors, ok := adjList[source]; ok {
        for _, neighbor := range neighbors {
            *currPath = append(*currPath, neighbor)
            backtrack(neighbor, destination, currPath, shortestPaths, adjList)
            *currPath = (*currPath)[:len(*currPath)-1]
        }
    }
}

func bfs(
    beginWord string,
    endWord string,
    wordSet map[string]bool,
    adjList map[string][]string,
) {
    queue := []string{beginWord}
    // remove the root word which is the first layer in the BFS
    delete(wordSet, beginWord)
    isEnqueued := make(map[string]bool)
    isEnqueued[beginWord] = true

    for len(queue) > 0 {
        var visited []string
        for _, currWord := range queue {
            queue = queue[1:]
            // findNeighbors will have the adjacent words of the currWord
            neighbors := findNeighbors(currWord, wordSet)
            for _, neighbor := range neighbors {
                if !isEnqueued[neighbor] {
                    queue = append(queue, neighbor)
                    isEnqueued[neighbor] = true
                }
                adjList[neighbor] = append(adjList[neighbor], currWord)
                visited = append(visited, neighbor)
            }
        }
        // removing the words of the previous layer
        for _, word := range visited {
            delete(wordSet, word)
        }
    }
}
