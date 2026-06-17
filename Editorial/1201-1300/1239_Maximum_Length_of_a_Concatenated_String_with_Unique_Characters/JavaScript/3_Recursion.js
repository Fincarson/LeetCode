var maxLength = function(arr) {    
    // Use depth first search recursion through arr
    // building from an initial empty string
    return dfs(arr, 0, "")
};

var dfs = function(arr, pos, res) {    
    // Use a set to check res for duplicate characters
    let resSet = new Set(res.split(""))
    if (res.length !== resSet.size)
        return 0
        
    // Recurse through each possible next option
    // and find the best answer
    let best = res.length
    for (let i = pos; i < arr.length; i++)
        best = Math.max(best, dfs(arr, i + 1, res + arr[i]))
    return best
}
