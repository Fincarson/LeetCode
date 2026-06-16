from collections import Counter
class Solution:
    def singleNumber(self, nums: int) -> List[int]:
        hashmap = Counter(nums)
        return [x for x in hashmap if hashmap[x] == 1]
