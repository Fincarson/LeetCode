class UnionFind:
    """
        Implementation of UnionFind without load-balancing.
    """
    def __init__(self, size) -> None:
        """
        container to hold the group id for each member
        Note: the index of member starts from 1,
            thus we add one more element to the container.
        """
        self.group = [i for i in range(size + 1)]
        # the rank of each node for later rebalancing
        self.rank = [0] * (size + 1)

    def find(self, person: int) -> int:
        """
            return the group id that the person belongs to
        """
        if self.group[person] != person:
            self.group[person] = self.find(self.group[person])
        return self.group[person]

    def union(self, person_1: int, person_2: int) -> bool:
        """
            Join the groups together.
            return:
                false when the two persons belong to the same group already,
                otherwise true
        """
        group_1 = self.find(person_1)
        group_2 = self.find(person_2)
        if group_1 == group_2:
            return False

        # attach the group of lower rank to the group with higher rank
        if self.rank[group_1] > self.rank[group_2]:
            self.group[group_2] = group_1
        elif self.rank[group_1] < self.rank[group_2]:
            self.group[group_1] = group_2
        else:
            self.group[group_1] = group_2
            self.rank[group_2] += 1

        return True


class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        ordered_edges = []
        # add the virtual vertex (index with 0) along with the new edges.
        for index, weight in enumerate(wells):
            ordered_edges.append((weight, 0, index+1))

        # add the existing edges
        for house_1, house_2, weight in pipes:
            ordered_edges.append((weight, house_1, house_2))

        # sort the entire edges by their weights
        ordered_edges.sort(key=lambda x: x[0])

        # iterate through the ordered edges
        uf = UnionFind(n)
        total_cost = 0
        for cost, house_1, house_2 in ordered_edges:
            # determine if we should add the new edge to the final MST
            if uf.union(house_1, house_2):
                total_cost += cost

        return total_cost
