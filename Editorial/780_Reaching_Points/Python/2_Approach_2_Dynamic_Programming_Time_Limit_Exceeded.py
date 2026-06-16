class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        seen = set()
        def search(x, y):
            if (x, y) in seen: return
            if x > tx or y > ty: return
            seen.add((x, y))
            search(x+y, y)
            search(x, x+y)

        search(sx, sy)
        return (tx, ty) in seen
