class Solution:
    maxValue = 1000
    # Array to store precomputed pivot values
    precompute = [0] * (maxValue + 1) # Initializing to 0

    def pivotInteger(self, n: int) -> int:
        # Check if precompute array is not initialized
        if self.precompute[1] == 0:
            for i in range(1, self.maxValue + 1):
                sum_val = i * (i + 1) // 2

                j = 1
                # Find the first square greater than or equal to sum
                while j * j < sum_val:
                    j += 1

                # Check if j * j is equal to sum (pivot found), otherwise set to -1
                self.precompute[i] = j if j * j == sum_val else -1

        return self.precompute[n]
