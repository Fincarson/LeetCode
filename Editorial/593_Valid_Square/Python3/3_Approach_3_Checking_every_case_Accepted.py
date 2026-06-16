class Solution:
    def dist(self, p1, p2):
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (
            p2[0] - p1[0]
        )

    def check(self, p1, p2, p3, p4):
        return (
            self.dist(p1, p2) > 0
            and self.dist(p1, p3) > 0
            and self.dist(p1, p2) == self.dist(p2, p3)
            and self.dist(p2, p3) == self.dist(p3, p4)
            and self.dist(p3, p4) == self.dist(p4, p1)
            and self.dist(p1, p3) == self.dist(p2, p4)
        )

    def validSquare(self, p1, p2, p3, p4):
        return (
            self.check(p1, p2, p3, p4)
            or self.check(p1, p3, p2, p4)
            or self.check(p1, p2, p4, p3)
        )
