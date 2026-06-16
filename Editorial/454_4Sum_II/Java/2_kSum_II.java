import java.util.Map;

class Solution {
    private int[][] lsts;

    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        lsts = new int[][] { A, B, C, D };
        int k = lsts.length;
        Map<Integer, Integer> left = sumCount(0, k / 2);
        Map<Integer, Integer> right = sumCount(k / 2, k);
        int res = 0;
        for (int s : left.keySet())
            res += left.get(s) * right.getOrDefault(-s, 0);
        return res;
    }

    private Map<Integer, Integer> sumCount(int start, int end) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        for (int i = start; i < end; i++) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int a : lsts[i]) {
                for (int total : cnt.keySet()) {
                    map.put(total + a, map.getOrDefault(total + a, 0) + cnt.get(total));
                }
            }
            cnt = map;
        }
        return cnt;
    }
}
