class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        result = [0] * len(code)
        # If k is 0, return the result directly.
        if k == 0:
            return result
        for i in range(len(result)):
            if k > 0:
                # If k is greater than 0, store the sum of next k numbers.            
                for j in range(i + 1, i + k + 1):
                    result[i] += code[j % len(code)]
            else:
                # If k is less than 0, store the sum of previous -1*k numbers.
                for j in range(i - abs(k), i):
                    result[i] += code[(j + len(code)) % len(code)]
        return result
