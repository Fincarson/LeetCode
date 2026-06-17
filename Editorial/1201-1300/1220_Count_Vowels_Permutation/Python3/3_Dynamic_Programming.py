class Solution:
    def countVowelPermutation(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        @functools.cache
        def vowel_permutation_count(i, vowel):
            total = 1
            if i > 1:
                if vowel == 'a':
                    total = (vowel_permutation_count(i - 1, 'e') + vowel_permutation_count(i - 1, 'i') + vowel_permutation_count(i - 1, 'u')) % MOD
                elif vowel == 'e':
                    total = (vowel_permutation_count(i - 1, 'a') + vowel_permutation_count(i - 1, 'i')) % MOD
                elif vowel == 'i':
                    total = (vowel_permutation_count(i - 1, 'e') + vowel_permutation_count(i - 1, 'o')) % MOD
                elif vowel == 'o':
                    total = vowel_permutation_count(i - 1, 'i')
                else:
                    total = (vowel_permutation_count(i - 1, 'i') + vowel_permutation_count(i - 1, 'o')) % MOD
            return total

        return sum(vowel_permutation_count(n, vowel) for vowel in 'aeiou') % MOD
