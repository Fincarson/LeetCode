class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.n = n = len(characters)
        self.k = k = combinationLength
        self.chars = characters

        # generate first bitmask 1(k)0(n - k)
        self.b = (1 << n) - (1 << n - k)

    def next(self) -> str:
        # convert bitmasks into combinations
        # 111 --> "abc", 000 --> ""
        # 110 --> "ab", 101 --> "ac", 011 --> "bc"
        curr = [self.chars[j] for j in range(self.n) if self.b & (1 << self.n - j - 1)]
        
        # generate next bitmask
        self.b -= 1
        while self.b > 0 and bin(self.b).count('1') != self.k:
            self.b -= 1
        
        return ''.join(curr)

    def hasNext(self) -> bool:
        return self.b > 0
