var findLadders = function (beginWord, endWord, wordList) {
    let adjList = {};
    let currPath = [];
    let shortestPaths = [];

    function findNeighbors(word, wordSet) {
        let neighbors = [];
        let charList = Array.from(word);
        for (let i = 0; i < charList.length; i++) {
            let oldChar = charList[i];
            // replace the i-th character with all letters from a to z except the original character
            for (let c = "a".charCodeAt(0); c <= "z".charCodeAt(0); c++) {
                charList[i] = String.fromCharCode(c);
                let newWord = charList.join("");
                // skip if the character is same as original or if the word is not present in the wordSet
                if (c === oldChar.charCodeAt(0) || !wordSet.has(newWord)) {
                    continue;
                }
                neighbors.push(newWord);
            }
            charList[i] = oldChar;
        }
        return neighbors;
    }

    function backtrack(source, destination) {
        // store the path if we reached the endWord
        if (source === destination) {
            let tempPath = Array.from(currPath);
            tempPath.reverse();
            shortestPaths.push(tempPath);
        }

        if (!adjList.hasOwnProperty(source)) {
            return;
        }

        adjList[source].forEach((neighbor) => {
            currPath.push(neighbor);
            backtrack(neighbor, destination);
            currPath.pop();
        });
    }

    function bfs(beginWord, endWord, wordSet) {
        let q = [beginWord];
        // remove the root word which is the first layer in the BFS
        wordSet.delete(beginWord);
        let isEnqueued = { [beginWord]: true };
        while (q.length > 0) {
            // visited will store the words of current layer
            let visited = [];
            for (let i = q.length - 1; i >= 0; i--) {
                let currWord = q.shift();
                // findNeighbors will have the adjacent words of the currWord
                let neighbors = findNeighbors(currWord, wordSet);
                neighbors.forEach((neighbor) => {
                    visited.push(neighbor);
                    if (!adjList.hasOwnProperty(neighbor)) {
                        adjList[neighbor] = [];
                    }
                    // add the edge from neighbor to currWord in the list
                    adjList[neighbor].push(currWord);
                    if (!isEnqueued.hasOwnProperty(neighbor)) {
                        q.push(neighbor);
                        isEnqueued[neighbor] = true;
                    }
                });
            }
            // removing the words of the previous layer
            visited.forEach((word) => wordSet.delete(word));
        }
    }

    // copying the words into the set for efficient deletion in BFS
    let wordSet = new Set(wordList);
    bfs(beginWord, endWord, wordSet);

    // every path will start from the endWord
    currPath = [endWord];
    // traverse the DAG to find all the paths between endWord and beginWord
    backtrack(endWord, beginWord);

    return shortestPaths;
};
