class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.combinations = []
        n, k = len(characters), combinationLength
        
        # init the first combination
        nums = list(range(k)) + [n]
        
        j = 0
        while j < k:
            # add current combination
            curr = [characters[n - 1 - nums[i]] for i in range(k - 1, -1, -1)]
            self.combinations.append(''.join(curr))
            
            # Generate next combination.
            # Find the first j such that nums[j] + 1 != nums[j + 1].
            # Increase nums[j] by one.
            j = 0
            while j < k and nums[j + 1] == nums[j] + 1:
                nums[j] = j
                j += 1
            nums[j] += 1

    def next(self) -> str:
        return self.combinations.pop()

    def hasNext(self) -> bool:
        return self.combinations
