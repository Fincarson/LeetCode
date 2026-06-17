class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        res = []  # Target even number array
        freq = Counter(
            digits
        )  # The frequency of each number in the integer array
        # Enumerate all three-digit even numbers, maintain the frequency of each digit in the integer, and compare and judge whether it is the target even number
        for i in range(100, 1000, 2):
            freq1 = Counter([int(d) for d in str(i)])
            if all(freq[d] >= freq1[d] for d in freq1.keys()):
                res.append(i)
        return res
