class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def sum(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index = index & (index - 1)

        return result

    def insert(self, index, value):
        index += 1
        while index < len(self.tree):
            self.tree[index] += value
            index += index & -index


class MRUQueue:
    def __init__(self, n):
        self.size = n
        self.tree = FenwickTree(n + 2000)
        self.values = [0] * (n + 2000)
        for i in range(n):
            self.tree.insert(i, 1)
            self.values[i] = i + 1

    def fetch(self, k):
        low = 0
        high = self.size
        while low < high:
            mid = (low + high) >> 1
            if self.tree.sum(mid) < k:
                low = mid + 1
            else:
                high = mid

        self.tree.insert(low - 1, -1)
        self.tree.insert(self.size, 1)
        self.values[self.size] = self.values[low - 1]
        self.size += 1

        return self.values[low - 1]
