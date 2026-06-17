class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # Sort the original array
        arr.sort()

        # Initialize minimum difference `min_pair_diff` as a huge integer in order not 
        # to miss the absolute difference of the first pair. 
        min_pair_diff = float('inf')
        answer = []

        # Traverse the sorted array
        for i in range(len(arr) - 1):
            # For the absolute value `curr_pair_diff` of the current pair:
            curr_pair_diff = arr[i + 1] - arr[i]

            # If `curr_pair_diff` equals `min_pair_diff`, add this pair to the answer list.
            # If `curr_pair_diff` is smaller than `min_pair_diff`, discard all pairs in the answer list, 
            # add this pair to the answer list and update `min_pair_diff`.
            # If `curr_pair_diff` is larger than `min_pair_diff`, we just go ahead.
            if curr_pair_diff == min_pair_diff:
                answer.append([arr[i], arr[i + 1]])
            elif curr_pair_diff < min_pair_diff:
                answer = [[arr[i], arr[i + 1]]]
                min_pair_diff = curr_pair_diff

        return answer
