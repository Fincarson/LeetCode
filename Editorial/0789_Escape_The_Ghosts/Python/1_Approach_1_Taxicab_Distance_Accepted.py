class Solution(object):
    def escapeGhosts(self, ghosts, target):
        def taxi(P, Q):
            return abs(P[0] - Q[0]) + abs(P[1] - Q[1])

        return all(taxi([0, 0], target) < taxi(ghost, target)
                   for ghost in ghosts)
