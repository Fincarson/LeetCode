class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return (1 << N.bit_length()) - 1 - N if N else 1
