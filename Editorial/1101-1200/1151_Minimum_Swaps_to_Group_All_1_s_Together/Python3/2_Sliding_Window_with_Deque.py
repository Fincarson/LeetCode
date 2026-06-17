class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = sum(data)
        cnt_one = max_one = 0

        # maintain a deque with the size = ones
        deque = collections.deque()
        for i in range(len(data)):

            # we would always add the new element into the deque
            deque.append(data[i])
            cnt_one += data[i]

            # when there are more than ones elements in the deque,
            # remove the leftmost one
            if len(deque) > ones:
                cnt_one -= deque.popleft()
            max_one = max(max_one, cnt_one)
        return ones - max_one
