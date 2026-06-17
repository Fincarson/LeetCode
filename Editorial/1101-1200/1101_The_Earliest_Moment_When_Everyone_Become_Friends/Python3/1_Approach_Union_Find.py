class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        # In order to ensure that we find the _earliest_ moment,
        #  first of all we need to sort the events in chronological order.
        logs.sort(key = lambda x: x[0])

        uf = UnionFind(n)
        # Initially, we treat each individual as a separate group.
        group_cnt = n

        # We merge the groups along the way.
        for timestamp, friend_a, friend_b in logs:
            if uf.union(friend_a, friend_b):
                group_cnt -= 1

            # The moment when all individuals are connected to each other.
            if group_cnt == 1:
                return timestamp

        # There are still more than one groups left,
        #  i.e. not everyone is connected.
        return -1
