def palindromePairs(self, words: List[str]) -> List[List[int]]:

    pairs = []

    for i, word_1 in enumerate(words):
        for j, word_2 in enumerate(words):
            if i == j:
                continue
            combined_word = word_1 + word_2
            if combined_word == combined_word[::-1]:
                pairs.append([i, j])

    return pairs
