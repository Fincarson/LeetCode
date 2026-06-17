class MRUQueue:

    def __init__(self, n: int):
        self.total_elements = n
        self.BUCKET_SIZE = int(n**0.5)
        self.data = []
        self.index = []
        for number in range(1, n + 1):
            bucket_index = (number - 1) // self.BUCKET_SIZE
            if bucket_index == len(self.data):
                self.data.append([])
                self.index.append(number)
            self.data[-1].append(number)

    def fetch(self, k: int) -> int:
        bucket_index = self.upper_bound(self.index, k) - 1
        element = self.data[bucket_index][k - self.index[bucket_index]]
        del self.data[bucket_index][k - self.index[bucket_index]]
        for i in range(bucket_index + 1, len(self.index)):
            self.index[i] -= 1

        if len(self.data[-1]) >= self.BUCKET_SIZE:
            self.data.append([])
            self.index.append(self.total_elements)
        self.data[-1].append(element)

        if len(self.data[bucket_index]) == 0:
            del self.data[bucket_index]
            del self.index[bucket_index]

        return element

    def upper_bound(self, nums, target):
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            else:
                left = mid + 1
        return left
