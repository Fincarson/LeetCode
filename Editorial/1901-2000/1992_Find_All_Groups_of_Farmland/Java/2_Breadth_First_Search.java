class Solution {
    // The four directions in which traversal will be done.
    int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // Returns true if the coordinate is within the boundary of the matrix.
    private boolean isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    private Pair<Integer, Integer> BFS(Queue<Pair<Integer, Integer>> q, int[][] land,
        boolean[][] visited) {
        Pair<Integer, Integer> curr = new Pair<Integer, Integer>(0, 0);

        while (!q.isEmpty()) {
            curr = q.remove();

            int x = curr.getKey();
            int y = curr.getValue();

            for (int[] dir : dirs) {
                // Neighbor cell coordinates.
                int newX = x + dir[0], newY = y + dir[1];

                // If the neighbor is within the matrix and is a farmland cell and not visited yet.
                if (isWithinFarm(newX, newY, land.length, land[0].length) && !visited[newX][newY]
                        && land[newX][newY] == 1) {
                    visited[newX][newY] = true;
                    q.add(new Pair(newX, newY));
                }
            }
        }

        return curr;
    }

    public int[][] findFarmland(int[][] land) {
        boolean[][] visited = new boolean[land.length][land[0].length];
        List<int[]> ans = new ArrayList<>();


        for (int row1 = 0; row1 < land.length; row1++) {
            for (int col1 = 0; col1 < land[0].length; col1++) {
                if (land[row1][col1] == 1 && !visited[row1][col1]) {
                    Queue<Pair<Integer, Integer>> q = new LinkedList<>();

                    q.add(new Pair(row1, col1));
                    visited[row1][col1] = true;

                    Pair<Integer, Integer> last = BFS(q, land, visited);

                    int[] arr = new int[] {row1, col1, last.getKey(), last.getValue()};
                    ans.add(arr);
                }
            }
        }

        return ans.stream().toArray(int[][] :: new);
    }
}
