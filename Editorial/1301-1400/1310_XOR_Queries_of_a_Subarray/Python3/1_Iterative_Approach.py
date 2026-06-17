class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        result = []
        # Process each query
        for q in queries:
            xor_sum = 0
            # Calculate XOR for the range [q[0], q[1]]
            for i in range(q[0], q[1] + 1):
                xor_sum ^= arr[i]
            result.append(xor_sum)
        return result
