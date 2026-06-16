class Solution:
    def grayCode(self, n: int) -> List[int]:
        result = []
        self.grayCodeHelper(result, n)
        return result

    def grayCodeHelper(self, result: List[int], n: int):
        if n == 0:
            result.append(0)
            return
        # derive the n bits sequence from the (n - 1) bits sequence.
        self.grayCodeHelper(result, n - 1)
        currentSequenceLength = len(result)
        # Set the bit at position n - 1 (0 indexed) and assign it to mask.
        mask = 1 << (n - 1)
        for i in range(currentSequenceLength - 1, -1, -1):
            # mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
            result.append(result[i] | mask)
        return
