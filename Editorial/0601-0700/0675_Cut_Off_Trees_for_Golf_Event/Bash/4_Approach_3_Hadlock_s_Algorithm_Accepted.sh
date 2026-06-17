public int hadlocks(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
    int R = forest.size(), C = forest.get(0).size();
    Set<Integer> processed = new HashSet();
    Deque<int[]> deque = new ArrayDeque();
    deque.offerFirst(new int[]{0, sr, sc});
    while (!deque.isEmpty()) {
        int[] cur = deque.pollFirst();
        int detours = cur[0], r = cur[1], c = cur[2];
        if (!processed.contains(r*C + c)) {
            processed.add(r*C + c);
            if (r == tr && c == tc) {
                return Math.abs(sr-tr) + Math.abs(sc-tc) + 2 * detours;
            }
            for (int di = 0; di < 4; ++di) {
                int nr = r + dr[di];
                int nc = c + dc[di];
                boolean closer;
                if (di <= 1) closer = di == 0 ? r > tr : r < tr;
                else closer = di == 2 ? c > tc : c < tc;
                if (0 <= nr && nr < R && 0 <= nc && nc < C && forest.get(nr).get(nc) > 0) {
                    if (closer) deque.offerFirst(new int[]{detours, nr, nc});
                    else deque.offerLast(new int[]{detours+1, nr, nc});
                }
            }
        }
    }
    return -1;
}
