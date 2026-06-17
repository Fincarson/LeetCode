class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        # Dictionary to maintain frequency count for arr
        arrFreq = {}
        for num in arr:
            if num not in arrFreq:
                arrFreq[num] = 1
            else:
                arrFreq[num] += 1

        # Dictionary to maintain frequency count for arr
        targetFreq = {}
        for num in target:
            if num not in targetFreq:
                targetFreq[num] = 1
            else:
                targetFreq[num] += 1

        # Number of distinct elements of the 2 arrays are not equal
        if len(arrFreq) != len(targetFreq):
            return False

        for key in arrFreq:
            # Frequency for num differs
            if arrFreq[key] != targetFreq.get(key, 0):
                return False

        return True
