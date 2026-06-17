class Solution {

    public int treeDiameter(int[][] edges) {

        // build the adjacency list representation of the graph.
        List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
        for (int i = 0; i < edges.length + 1; ++i) {
            graph.add(new HashSet<Integer>());
        }
        for (int[] edge : edges) {
            Integer u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // find the outer most nodes, i.e. leaf nodes
        LinkedList<Integer> leaves = new LinkedList<Integer>();
        for (int vertex = 0; vertex < graph.size(); ++vertex) {
            if (graph.get(vertex).size() == 1)
                leaves.add(vertex);
        }

        // "peel" the graph layer by layer,
        // until we have the centroids left.
        int layers = 0;
        int vertexLeft = edges.length + 1;
        while (vertexLeft > 2) {
            vertexLeft -= leaves.size();

            LinkedList<Integer> nextLeaves = new LinkedList<Integer>();

            for (int leaf : leaves) {
                // the only neighbor left on the leaf node.
                int neighbor = graph.get(leaf).iterator().next();
                graph.get(neighbor).remove(leaf);
                if (graph.get(neighbor).size() == 1)
                    nextLeaves.add(neighbor);
            }

            layers += 1;
            leaves = nextLeaves;
        }

        if (vertexLeft == 1)
            return layers * 2;
        else
            return layers * 2 + 1;
    }
}
