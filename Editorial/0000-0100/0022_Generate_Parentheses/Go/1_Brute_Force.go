func isValid(pString string) bool {
    leftCount := 0
    for _, p := range pString {
        if p == '(' {
            leftCount++
        } else {
            leftCount--
        }
        if leftCount < 0 {
            return false
        }
    }
    return leftCount == 0
}

func generateParenthesis(n int) []string {
    var answer []string
    queue := list.New()
    queue.PushBack("")
    for queue.Len() > 0 {
        curElement := queue.Front()
        queue.Remove(curElement)
        curString := curElement.Value.(string)
        if len(curString) == 2*n {
            if isValid(curString) {
                answer = append(answer, curString)
            }
            continue
        }
        queue.PushBack(curString + ")")
        queue.PushBack(curString + "(")
    }
    return answer
}
