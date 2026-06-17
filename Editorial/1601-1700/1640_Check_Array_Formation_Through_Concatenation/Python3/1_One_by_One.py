class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        n = len(arr)
        i = 0
        while i < n:
            # find target piece
            for p in pieces:
                if p[0] == arr[i]:
                    break
            else:
                return False
            # check target piece
            # python saves the last iterated `p`
            for x in p:
                if x != arr[i]:
                    return False
                i += 1
        return True
