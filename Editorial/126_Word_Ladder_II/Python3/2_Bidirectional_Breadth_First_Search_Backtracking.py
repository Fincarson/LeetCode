class Solution:
    def __init__(self):
        self.adjList = {}
        self.currPath = []
        self.shortestPaths = []

    def findNeighbors(self, word, wordList):
        neighbors = []
        charList = list(word)
        for i in range(len(word)):
            oldChar = charList[i]
            for ch in range(97, 123):
                c = chr(ch)
                charList[i] = c
                if c == oldChar or "".join(charList) not in wordList:
                    continue
                neighbors.append("".join(charList))
            charList[i] = oldChar
        return neighbors

    def backtrack(self, source, destination):
        if source == destination:
            tempPath = list(self.currPath)
            self.shortestPaths.append(tempPath)
        for i in range(len(self.adjList.get(source, []))):
            self.currPath.append(self.adjList[source][i])
            self.backtrack(self.adjList[source][i], destination)
            self.currPath.pop()

    def addEdge(self, word1, word2, direction):
        if direction == 1:
            self.adjList[word1] = self.adjList.get(word1, []) + [word2]
        else:
            self.adjList[word2] = self.adjList.get(word2, []) + [word1]

    def bfs(self, beginWord, endWord, wordList):
        if endWord not in wordList:
            return False
        if beginWord in wordList:
            wordList.remove(beginWord)
        forwardQueue = set([beginWord])
        backwardQueue = set([endWord])
        found = False
        direction = 1
        while len(forwardQueue) != 0:
            visited = set()
            if len(forwardQueue) > len(backwardQueue):
                forwardQueue, backwardQueue = backwardQueue, forwardQueue
                direction ^= 1
            for currWord in forwardQueue:
                neighbors = self.findNeighbors(currWord, wordList)
                for word in neighbors:
                    if word in backwardQueue:
                        found = True
                        self.addEdge(currWord, word, direction)
                    elif (
                        not found
                        and word in wordList
                        and word not in forwardQueue
                    ):
                        visited.add(word)
                        self.addEdge(currWord, word, direction)
            for currWord in forwardQueue:
                if currWord in wordList:
                    wordList.remove(currWord)
            if found:
                break
            forwardQueue = visited
        return found

    def findLadders(self, beginWord, endWord, wordList):
        copiedWordList = set(wordList)
        sequence_found = self.bfs(beginWord, endWord, copiedWordList)
        if sequence_found == False:
            return self.shortestPaths
        self.currPath.append(beginWord)
        self.backtrack(beginWord, endWord)
        return self.shortestPaths
