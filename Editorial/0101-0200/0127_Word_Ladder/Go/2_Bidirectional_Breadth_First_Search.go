var (
    AllComboDict map[string][]string
    L            int
)

func visitWordNode(
    Q *list.List,
    Visited *map[string]int,
    OthersVisited *map[string]int,
) int {
    for sz := Q.Len(); sz > 0; sz-- {
        element := Q.Front()
        node := element.Value.([2]interface{})
        Q.Remove(element)
        word := node[0].(string)
        level := node[1].(int)
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:]
            for _, adjacentWord := range AllComboDict[newWord] {
                if _, ok := (*OthersVisited)[adjacentWord]; ok {
                    return level + (*OthersVisited)[adjacentWord]
                }
                if _, ok := (*Visited)[adjacentWord]; !ok {
                    (*Visited)[adjacentWord] = level + 1
                    Q.PushBack([2]interface{}{adjacentWord, level + 1})
                }
            }
        }
    }
    return -1
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
    wordSet := make(map[string]bool)
    for _, word := range wordList {
        wordSet[word] = true
    }
    if _, ok := wordSet[endWord]; !ok {
        return 0
    }
    AllComboDict = make(map[string][]string)
    L = len(beginWord)
    for _, word := range wordList {
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:]
            AllComboDict[newWord] = append(AllComboDict[newWord], word)
        }
    }
    q_beg := list.New()
    q_beg.PushBack([2]interface{}{beginWord, 1})
    q_end := list.New()
    q_end.PushBack([2]interface{}{endWord, 1})
    visited_beg := make(map[string]int)
    visited_beg[beginWord] = 1
    visited_end := make(map[string]int)
    visited_end[endWord] = 1
    for q_beg.Len() > 0 && q_end.Len() > 0 {
        ans := -1
        if q_beg.Len() <= q_end.Len() {
            ans = visitWordNode(q_beg, &visited_beg, &visited_end)
        } else {
            ans = visitWordNode(q_end, &visited_end, &visited_beg)
        }
        if ans > -1 {
            return ans
        }
    }
    return 0
}
