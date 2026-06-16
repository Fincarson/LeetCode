public class Solution {
    public int MaximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Array.Sort(hBars);
        Array.Sort(vBars);
        int hmax = 1, vmax = 1;
        int hcur = 1, vcur = 1;
        for (int i = 1; i < hBars.Length; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }
            hmax = Math.Max(hmax, hcur);
        }
        for (int i = 1; i < vBars.Length; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = Math.Max(vmax, vcur);
        }
        int side = Math.Min(hmax, vmax) + 1;
        return side * side;
    }
}
