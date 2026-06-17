class Solution {

    public int treeDiameter(int[][] edges) {

        List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
        for (int i = 0; i < edges.length + 1; ++i) {
            graph.add(new HashSet<Integer>());
        }

        for (int[] edge : edges) {
            Integer u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // 1). find one of the farthest nodes
        // farthest_node, distance_1 = bfs(0)
        int[] nodeDistance = bfs(0, graph);
        // 2). find the other farthest node
        // and the distance between two farthest nodes
        // another_farthest_node, distance_2 = bfs(farthest_node)
        nodeDistance = bfs(nodeDistance[0], graph);

        return nodeDistance[1];
    }

    /**
     * return the farthest node from the 'start' node and the distance between them.
     */
    private int[] bfs(int start, List<Set<Integer>> graph) {
        boolean[] visited = new boolean[graph.size()];
        visited[start] = true;

        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.addLast(start);
        Integer lastNode = start, distance = -1;

        while (queue.size() > 0) {
            LinkedList<Integer> nextQueue = new LinkedList<Integer>();

            while (queue.size() > 0) {
                int nextNode = queue.removeFirst();
                for (Integer neighbor : graph.get(nextNode)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nextQueue.addLast(neighbor);
                        lastNode = neighbor;
                    }
                }
            }
            // increase the distance for each level of BFS traversal.
            distance += 1;
            queue = nextQueue;
        }

        return new int[] {lastNode, distance};
    }

}
