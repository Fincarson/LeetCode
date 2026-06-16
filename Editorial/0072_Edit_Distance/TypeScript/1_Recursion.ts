function minDistance(word1: string, word2: string): number {
    return minDistanceRecur(word1, word2, word1.length, word2.length);
}
function minDistanceRecur(
    word1: string,
    word2: string,
    word1Index: number,
    word2Index: number,
): number {
    if (word1Index == 0) {
        return word2Index;
    }
    if (word2Index == 0) {
        return word1Index;
    }
    if (word1.charAt(word1Index - 1) == word2.charAt(word2Index - 1)) {
        return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
    } else {
        let insertOperation = minDistanceRecur(
            word1,
            word2,
            word1Index,
            word2Index - 1,
        );
        let deleteOperation = minDistanceRecur(
            word1,
            word2,
            word1Index - 1,
            word2Index,
        );
        let replaceOperation = minDistanceRecur(
            word1,
            word2,
            word1Index - 1,
            word2Index - 1,
        );
        return (
            Math.min(
                insertOperation,
                Math.min(deleteOperation, replaceOperation),
            ) + 1
        );
    }
}
