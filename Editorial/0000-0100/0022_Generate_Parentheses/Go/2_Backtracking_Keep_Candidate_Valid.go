func generateParenthesis(n int) []string {
    var answer []string
    var backtracking func(currString string, leftCount, rightCount int)
    backtracking = func(currString string, leftCount, rightCount int) {
        if len(currString) == 2*n {
            answer = append(answer, currString)
            return
        }
        if leftCount < n {
            backtracking(currString+"(", leftCount+1, rightCount)
        }
        if rightCount < leftCount {
            backtracking(currString+")", leftCount, rightCount+1)
        }
    }
    backtracking("", 0, 0)
    return answer
}
