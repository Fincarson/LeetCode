import java.awt.Point;

class Solution {
    Set<Point> seen;
    int tx, ty;

    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        seen = new HashSet();
        this.tx = tx;
        this.ty = ty;
        search(new Point(sx, sy));
        return seen.contains(new Point(tx, ty));
    }

    public void search(Point P) {
        if (seen.contains(P)) return;
        if (P.x > tx || P.y > ty) return;
        seen.add(P);
        search(new Point(P.x + P.y, P.y));
        search(new Point(P.x, P.x + P.y));
    }
}
