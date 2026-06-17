from collections import Counter


class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        def sum_count(lsts: List[List[int]]) -> Counter:
            res = Counter({0: 1})
            for lst in lsts:
                temp = Counter()
                for a in lst:
                    for total in res:
                        temp[total + a] += res[total]
                res = temp
            return res

        lsts = [A, B, C, D]
        k = len(lsts)
        left, right = sum_count(lsts[:k//2]), sum_count(lsts[k//2:])
        return sum(left[s]*right[-s] for s in left)
