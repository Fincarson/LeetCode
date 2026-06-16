class Solution:
    def canPartitionKSubsets(self, arr: List[int], k: int) -> bool:
        total_array_sum = sum(arr)
        n = len(arr)

        # If the total sum is not divisible by k, we can't make subsets.
        if total_array_sum % k != 0:
            return False

        target_sum = total_array_sum // k
        taken = [False] * n
        
        def backtrack(count: int, curr_sum: int) -> bool:
            n = len(arr)

            # We made k - 1 subsets with target sum and the last subset will also have target sum.
            if count == k - 1:
                return True

            # Current subset-sum exceeds target sum, no need to proceed further.
            if curr_sum > target_sum:
                return False

            # When current subset sum reaches target sum then one subset is made.
            # Increment count and reset current subset sum to 0.
            if curr_sum == target_sum:
                return backtrack(count + 1, 0)

            # Try not picked elements to make some combinations.
            for j in range(n):
                if not taken[j]:
                    # Include this element in current subset.
                    taken[j] = True

                    # If using current jth element in this subset leads to make all valid subsets.
                    if backtrack(count, curr_sum + arr[j]):
                        return True

                    # Backtrack step.
                    taken[j] = False

            # We were not able to make a valid combination after picking 
            # each element from the array, hence we can't make k subsets.
            return False

        return backtrack(0, 0)
