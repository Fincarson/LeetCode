class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        if sx > tx or sy > ty: return False
        if sx == tx and sy == ty: return True
        return self.reachingPoints(sx+sy, sy, tx, ty) or \
               self.reachingPoints(sx, sx+sy, tx, ty)
