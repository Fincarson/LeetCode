func min(a int, b int, c int) int {
    if a <= b && a <= c {
        return a
    }
    if b <= a && b <= c {
        return b
    }
    return c
}

func minDistanceRecur(
    word1 string,
    word2 string,
    word1Index int,
    word2Index int,
) int {
    if word1Index == 0 {
        return word2Index
    }
    if word2Index == 0 {
        return word1Index
    }
    if word1[word1Index-1] == word2[word2Index-1] {
        return minDistanceRecur(word1, word2, word1Index-1, word2Index-1)
    } else {
        insertOperation := minDistanceRecur(word1, word2, word1Index, word2Index-1)
        deleteOperation := minDistanceRecur(word1, word2, word1Index-1, word2Index)
        replaceOperation := minDistanceRecur(word1, word2, word1Index-1, word2Index-1)
        return min(insertOperation, deleteOperation, replaceOperation) + 1
    }
}

func minDistance(word1 string, word2 string) int {
    return minDistanceRecur(word1, word2, len(word1), len(word2))
}
