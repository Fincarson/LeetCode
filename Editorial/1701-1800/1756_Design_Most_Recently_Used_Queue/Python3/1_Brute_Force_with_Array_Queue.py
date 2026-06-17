class MRUQueue:

    def __init__(self, n: int):
        # Initialize the queue with numbers from 1 to n
        self.queue = [i for i in range(1, n + 1)]

    def fetch(self, k: int) -> int:
        # Get the k-th element (1-indexed)
        value = self.queue.pop(k - 1)
        # Append the element to the end of the queue
        self.queue.append(value)
        return value
