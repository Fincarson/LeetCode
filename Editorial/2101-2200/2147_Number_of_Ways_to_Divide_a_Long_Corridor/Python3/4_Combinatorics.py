class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Store 1000000007 in a variable for convenience
        MOD = 1_000_000_007

        # Store indices of S in an array
        indices = []
        for i, thing in enumerate(corridor):
            if thing == "S":
                indices.append(i)
        
        # When division is not possible
        if indices == [] or len(indices) % 2 == 1:
            return 0
        
        # Total number of ways
        count = 1

        # Take the product of non-paired neighbors
        previous_pair_last = 1
        current_pair_first = 2
        while current_pair_first < len(indices):
            count *= (indices[current_pair_first] - indices[previous_pair_last])
            count %= MOD
            previous_pair_last += 2
            current_pair_first += 2

        # Return the number of ways
        return count
