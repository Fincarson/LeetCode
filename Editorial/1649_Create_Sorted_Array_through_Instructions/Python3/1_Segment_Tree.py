class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        # implement Segment Tree
        def update(index, value, tree, m):
            index += m
            tree[index] += value
            while index > 1:
                index >>= 1
                tree[index] = tree[index << 1] + tree[(index << 1)+1]

        def query(left, right, tree, m):
            result = 0
            left += m
            right += m
            while left < right:
                if left & 1:
                    result += tree[left]
                    left += 1
                left >>= 1
                if right & 1:
                    right -= 1
                    result += tree[right]
                right >>= 1
            return result

        MOD = 10**9+7
        m = max(instructions)+1
        tree = [0]*(2*m)
        cost = 0
        for x in instructions:
            left_cost = query(0, x, tree, m)
            right_cost = query(x+1, m, tree, m)
            cost += min(left_cost, right_cost)
            update(x, 1, tree, m)
        return cost % MOD
