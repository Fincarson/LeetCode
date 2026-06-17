from collections import deque

class FirstUnique:
    def __init__(self, nums: List[int]):
        self._queue = deque(nums)

    def showFirstUnique(self):
        for item in self._queue:
            if self._queue.count(item) == 1:
                return item
        return -1

    def add(self, value):
        self._queue.append(value)
