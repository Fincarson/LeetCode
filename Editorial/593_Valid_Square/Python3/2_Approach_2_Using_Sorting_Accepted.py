class Solution:
    def dist(self, p1, p2):
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (
            p2[0] - p1[0]
        )

    def validSquare(self, p1, p2, p3, p4):
        p = [p1, p2, p3, p4]
        p.sort(key=lambda l: (l[0], l[1]))
        return (
            self.dist(p[0], p[1]) != 0
            and self.dist(p[0], p[1]) == self.dist(p[1], p[3])
            and self.dist(p[1], p[3]) == self.dist(p[3], p[2])
            and self.dist(p[3], p[2]) == self.dist(p[2], p[0])
            and self.dist(p[0], p[3]) == self.dist(p[1], p[2])
        )
