class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        word1_elem_freq = Counter(word1)
        word2_elem_freq = Counter(word2)

        return set(word1_elem_freq) == set(word2_elem_freq) and sorted(word1_elem_freq.values()) == sorted(word2_elem_freq.values())
