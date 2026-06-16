from math import log2
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        # l is a length of N in binary representation
        l = floor(log2(N)) + 1        
        # bitmask has the same length as N and contains only ones 1...1
        bitmask = (1 << l) - 1
        # Flip all bits
        return bitmask ^ N
