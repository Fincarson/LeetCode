class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        queue = deque(nestedList)

        depth = 1
        total = 0

        while len(queue) > 0:
            for i in range(len(queue)):
                nested = queue.pop()
                if nested.isInteger():
                    total += nested.getInteger() * depth
                else:
                    queue.extendleft(nested.getList())
            depth += 1

        return total
