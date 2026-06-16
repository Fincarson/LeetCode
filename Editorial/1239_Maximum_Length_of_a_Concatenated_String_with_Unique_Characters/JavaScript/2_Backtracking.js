var maxLength = function(arr) {    
    // Use depth first search recursion through arr
    // with backracking and a map for results
    return backtracking(arr, 0, new Map())
};

var backtracking = function(arr, pos, resMap) {    
    // Check for duplicate characters
    for (let val of resMap.values())
        if (val > 1)
            return 0
    
    // Recurse through each possible next option
    // and find the best answer
    let best = resMap.size
    for (let i = pos; i < arr.length; i++) {        
        // Add the current word to the result map
        // and recurse to the next position
        let word = arr[i]
        for (let c of word)
            resMap.set(c, (resMap.get(c) || 0) + 1)
        best = Math.max(best, backtracking(arr, i + 1, resMap))
        
        // Backtrack the result map before continuing
        for (let c of word) {
            if (resMap.get(c) === 1) {
                resMap.delete(c)
            } else {
                resMap.set(c, resMap.get(c) - 1)
            }
        }
    }
    return best
};
