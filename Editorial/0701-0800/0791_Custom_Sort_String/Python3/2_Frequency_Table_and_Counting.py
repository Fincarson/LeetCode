class Solution:
    def customSortString(self, order: str, s: str) -> str:
        s_elem_freq = Counter(s)
        s_permutation = []

        for char in order:
            # Elem to be Ordered
            if char in s_elem_freq:
                s_permutation.append(char * s_elem_freq[char])
                del s_elem_freq[char]

        for unordered_elem in s_elem_freq:
            s_permutation.append(unordered_elem * s_elem_freq[unordered_elem])

        return ''.join(s_permutation)
